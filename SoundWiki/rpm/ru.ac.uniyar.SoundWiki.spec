Name:       ru.ac.uniyar.SoundWiki
Summary:    Приложение, которое выводит информацию о музыкальных композициях.
Version:    1.0.0
Release:    1
License:    BSD-3-Clause
URL:        https://auroraos.ru
Source0:    %{name}-%{version}.tar.bz2

Requires:   sailfishsilica-qt5 >= 0.10.9
BuildRequires:  pkgconfig(auroraapp)
BuildRequires:  pkgconfig(Qt5Core)
BuildRequires:  pkgconfig(Qt5Qml)
BuildRequires:  pkgconfig(Qt5Quick)

%description
На главном экране приложения имеется форма поиска. Приложение выводит список найденных по запросу треков с основной информацией о них: название композиции, название альбома, исполнитель, жанр/категория. Также приложение должно выводить на отдельном экране расширенную информацию о треке: название композиции, название альбома, исполнитель, продолжительность, жанр/категория, описание, картинка. Трек можно добавить в избранное, тогда вся информация о нем должна храниться в базе данных на локальном устройстве. Пользователь может просмотреть список избарнных треков, открыть расширенную информацию о конкретном треке, удалить трек из избранного.

%prep
%autosetup

%build
%cmake -GNinja
%ninja_build

%install
%ninja_install

%files
%defattr(-,root,root,-)
%{_bindir}/%{name}
%defattr(644,root,root,-)
%{_datadir}/%{name}
%{_datadir}/applications/%{name}.desktop
%{_datadir}/icons/hicolor/*/apps/%{name}.png
