import QtQuick 2.0
import QtQuick.LocalStorage 2.0

QtObject {
    property var db

    function createSongTable() {
        db.transaction(function (tx) {
            tx.executeSql("CREATE TABLE IF NOT EXISTS song (" +
             "id INTEGER PRIMARY KEY, " +
             "title TEXT, " +
             "artist TEXT, " +
             "genre TEXT, " +
             "cover TEXT, " +
             "path TEXT, " +
             "duration INTEGER, " +
             "albumId INTEGER, " +
             "albumName TEXT, " +
             "albumYear INTEGER, " +
             "countTracks INTEGER)");
        });
    }

    function retrieveSongs(callback) {
        db.readTransaction(function (tx) {
            var result = tx.executeSql("SELECT * FROM song");
            callback(result.rows);
        });
    }

    function insertSong(song_id, title, artist,
                        genre, cover, path, duration,
                        album_id, album_name, album_year,
                        count_tracks) {
        db.transaction(function (tx) {
            tx.executeSql(
                 "INSERT INTO song (id, title, artist, genre,
                 cover, path, duration, albumId, albumName,
                 albumYear, countTracks) " +
                 "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)",
                 [song_id, title, artist, genre, cover, path, duration,
                 album_id, album_name, album_year, count_tracks]
            );
        });
    }

    function isSongInFavourites(song_id)
    {
        var isExists = false;
        db.readTransaction(function(tx)
        {
           var result = tx.executeSql("SELECT * FROM song WHERE id = ?", [song_id]);
           isExists = result.rows.length > 0;
        });

        return isExists;
    }

    function deleteSong(id)
    {
        var pathToRemove = "";

        db.transaction(function(tx) {
            var result = tx.executeSql("SELECT path FROM song WHERE id = ?", [id]);
            var path = result.rows.length > 0
                     ? (result.rows.item(0).path || "")
                     : "";

            tx.executeSql("DELETE FROM song WHERE id = ?", [id]);

            if (path !== "") {
                var usage = tx.executeSql(
                    "SELECT COUNT(*) AS cnt FROM song WHERE path = ?", [path]);

                if (usage.rows.item(0).cnt === 0)
                    pathToRemove = path;
            }
        });

        return pathToRemove;
    }

    function isPathUsed(path)
    {
        if (path === "")
            return false;

        var used = false;

        db.readTransaction(function(tx) {
            var result = tx.executeSql(
                "SELECT COUNT(*) AS cnt FROM song WHERE path = ?", [path]);
            used = result.rows.item(0).cnt > 0;
        });

        return used;
    }

    function getPath(id)
    {
        var path = "";

        db.readTransaction(function(tx) {
            var result = tx.executeSql("SELECT path FROM song WHERE id = ?", [id]);
            if (result.rows.length > 0)
                path = result.rows.item(0).path || "";
        });

        return path;
    }

    function setPathIfExists(id, path)
    {
        var updated = false;

        db.transaction(function(tx) {
            var result = tx.executeSql(
                "UPDATE song SET path = ? WHERE id = ?", [path, id]);
            updated = result.rowsAffected > 0;
        });

        return updated;
    }

    function resetDatabase() {
        db.transaction(function (tx) {
            tx.executeSql("DROP TABLE IF EXISTS song");
        });
    }

    function putSongsInDatabase()
    {
        insertSong(1, "Digital Bath",
                   "Deftones",
                   "alternativemetal",
                   "https://avatars.yandex.net/get-music-content/49707/3d71ea0e.a.3389746-1/600x600",
                   255370,
                   1,
                   "The Studio Album Collection",
                   2016,
                   78);

        insertSong(2,
                   "Phantom Bride",
                   "Deftones",
                   "alternativemetal",
                   "https://avatars.yandex.net/get-music-content/3226792/9c0574a5.p.48770/600x600",
                   293050,
                   1,
                   "Gore",
                   2016,
                   11);
    }

    function createDbForTests()
    {
        resetDatabase();
        createSongTable();
        putSongsInDatabase();
    }

    Component.onCompleted: {
        db = LocalStorage.openDatabaseSync("song", "1.0");
        createSongTable();
    }
}
