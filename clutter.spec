%global _changelog_trimtime %(date +%s -d "1 year ago")

Name:          clutter
Version:       1.14.4
Release:       12%{?dist}.1
Summary:       Open Source software library for creating rich graphical user interfaces

Group:         Development/Libraries
License:       LGPLv2+
URL:           http://www.clutter-project.org/
Source0:       http://download.gnome.org/sources/clutter/1.14/clutter-%{version}.tar.xz
# https://bugzilla.gnome.org/show_bug.cgi?id=692706
Patch0:        0001-cally-Use-a-weak-pointer-to-hold-the-key-focus-in-Ca.patch
# https://bugzilla.gnome.org/show_bug.cgi?id=701974
Patch1:        0001-x11-trap-errors-when-calling-XIQueryDevice.patch
# https://bugzilla.redhat.com/show_bug.cgi?id=1039137
Patch2:        0001-clutter-text-prevent-reset-of-user-set-font-descript.patch
# https://bugzilla.gnome.org/show_bug.cgi?id=703969
Patch3:       xi2-device-manager-cleanups.patch

# https://bugzilla.gnome.org/show_bug.cgi?id=719367
Patch4:        Bind-constraints-Don-t-force-redraws-on-source-relay.patch
# https://bugzilla.gnome.org/show_bug.cgi?id=719368
Patch5:        Don-t-queue-redraws-when-reallocating-actor-that-hav.patch
# https://bugzilla.gnome.org/show_bug.cgi?id=719901
Patch6:        ClutterStageCogl-Ignore-a-clip-the-size-of-the-stage.patch
# https://bugzilla.gnome.org/show_bug.cgi?id=732706
Patch7:        Allow-setting-up-quad-buffer-stereo-output.patch
# https://bugzilla.redhat.com/show_bug.cgi?id=975171
Patch8:        0001-clutter-offscreen-effect-Allocate-the-cogl-texture-d.patch

# CVE-2015-3213 - https://bugzilla.redhat.com/show_bug.cgi?id=1227103
Patch9:        0001-gesture-action-fix-memory-corruption.patch

%define cogl_version 1.14.0-6

BuildRequires: glib2-devel mesa-libGL-devel pkgconfig pango-devel
BuildRequires: cairo-gobject-devel gdk-pixbuf2-devel atk-devel
BuildRequires: cogl-devel >= %{cogl_version}
BuildRequires: gobject-introspection-devel >= 0.9.6
BuildRequires: gtk3-devel
BuildRequires: json-glib-devel >= 0.12.0
BuildRequires: libXcomposite-devel
BuildRequires: libXdamage-devel
BuildRequires: libXi-devel
Requires:      gobject-introspection
Requires:      cogl >= %{cogl_version}

# F18
Obsoletes:     clutter-gtk010 < 0.11.4-9
Obsoletes:     clutter-gtk010-devel < 0.11.4-9
Obsoletes:     clutter-sharp < 0-0.17
Obsoletes:     clutter-sharp-devel < 0-0.17
Obsoletes:     pyclutter < 1.3.2-13
Obsoletes:     pyclutter-devel < 1.3.2-13
Obsoletes:     pyclutter-gst < 1.0.0-10
Obsoletes:     pyclutter-gst-devel < 1.0.0-10
Obsoletes:     pyclutter-gtk < 0.10.0-14
Obsoletes:     pyclutter-gtk-devel < 0.10.0-14

%description
Clutter is an open source software library for creating fast,
visually rich graphical user interfaces. The most obvious example
of potential usage is in media center type applications.
We hope however it can be used for a lot more.

%package devel
Summary:       Clutter development environment
Group:         Development/Libraries
Requires:      %{name} = %{version}-%{release}
Requires:      pkgconfig glib2-devel pango-devel fontconfig-devel
Requires:      mesa-libGL-devel
Requires:      gobject-introspection-devel

%description devel
Header files and libraries for building a extension library for the
clutter

%package       doc
Summary:       Documentation for %{name}
Group:         Documentation
Requires:      %{name} = %{version}-%{release}

%description   doc
Clutter is an open source software library for creating fast,
visually rich graphical user interfaces. The most obvious example
of potential usage is in media center type applications.
We hope however it can be used for a lot more.

This package contains documentation for clutter.

%prep
%setup -q
%patch0 -p1 -b .cally_crash
%patch1 -p1 -b .xi2-crash
%patch2 -p1 -b .font-switch
%patch3 -p1 -b .xi2-device-manager-cleanups
%patch4 -p1 -b .bind-contraints
%patch5 -p1 -b .unmoved-actors
%patch6 -p1 -b .stage-sized-clip
%patch7 -p1 -b .quadbuffer-stereo
%patch8 -p1 -b .allocate-offscreen-effect-texture
%patch9 -p1 -b .CVE-2015-3213

%build
(autoreconf;
 %configure $CONFIGFLAGS \
	--enable-xinput
 # clutter git ships with some magic to put the git log in shipped tarballs
 # which gets listed in files; don't blow up if it's missing
 if ! test -f ChangeLog; then
   echo "Created from snapshot" > ChangeLog
 fi
)

make %{?_smp_mflags} V=1

%install
make install DESTDIR=%{buildroot} INSTALL='install -p'

#Remove libtool archives.
find %{buildroot} -name '*.la' -exec rm -f {} ';'

%find_lang clutter-1.0

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files -f clutter-1.0.lang
%doc COPYING NEWS README
%{_libdir}/*.so.0
%{_libdir}/*.so.0.*
%{_libdir}/girepository-1.0/*.typelib

%files devel
%doc ChangeLog
%{_includedir}/*
%{_libdir}/*.so
%{_libdir}/pkgconfig/*.pc
%{_datadir}/gir-1.0/*.gir

%files doc
%{_datadir}/gtk-doc/html/clutter
%{_datadir}/gtk-doc/html/cally

%changelog
* Tue Jul 28 2015 Scientific Linux Auto Patch Process <SCIENTIFIC-LINUX-DEVEL@LISTSERV.FNAL.GOV>
- Eliminated rpmbuild "bogus date" error due to inconsistent weekday,
  by assuming the date is correct and changing the weekday.
  Sun Mar 23 2007 --> Sun Mar 18 2007 or Fri Mar 23 2007 or Sun Mar 25 2007 or ....
  Sun Mar 24 2007 --> Sun Mar 18 2007 or Sat Mar 24 2007 or Sun Mar 25 2007 or ....
  Sun Mar 27 2007 --> Sun Mar 25 2007 or Tue Mar 27 2007 or Sun Apr 01 2007 or ....
  Sun Mar 28 2007 --> Sun Mar 25 2007 or Wed Mar 28 2007 or Sun Apr 01 2007 or ....
  Wed Feb 11 2010 --> Wed Feb 10 2010 or Thu Feb 11 2010 or Wed Feb 17 2010 or ....
  Tue Mar 20 2010 --> Tue Mar 16 2010 or Sat Mar 20 2010 or Tue Mar 23 2010 or ....

* Tue Jun 02 2015 Ray Strode <rstrode@redhat.com> 1.14.4-12.1
- Fix crash when doing gestures at unlock screen
  Resolves: rhbz#1227103

* Mon Nov 03 2014 Florian Müllner <fmuellner@redhat.com> 1.14.4-12
- Include upstream patch to prevent a crash when hitting hardware limits
  Resolves: rhbz#1115162

* Tue Sep 30 2014 Owen Taylor <otaylor@redhat.com> 1.14.4-11
- Fix a typo in the Requires

* Thu Jul 17 2014 Owen Taylor <otaylor@redhat.com> 1.14.4-10
- Add patch for quadbuffer stereo suppport
  Resolves: rhbz#1108891

* Tue Feb 11 2014 Owen Taylor <otaylor@redhat.com> - 1.14.4-9
- Add upstream patches fixing problems that resulted in the entire
  screen being redrawn too often with gnome shell.
  Resolves: rhbz#1034941

* Fri Jan 24 2014 Daniel Mach <dmach@redhat.com> - 1.14.4-8
- Mass rebuild 2014-01-24

* Sat Jan 11 2014 Florian Müllner <fmuellner@redhat.com> - 1.14.4-7
- Backport device manager cleanups for pointer emulation for touch events
  in mutter
  Resolves: rhbz#1051029

* Mon Jan  6 2014 Rui Matos <rmatos@redhat.com> - 1.14.4-5
- Resolves: rhbz#1039137 - gnome-shell text labels switch font temporarily until they redraw again

* Fri Dec 27 2013 Daniel Mach <dmach@redhat.com> - 1.14.4-4
- Mass rebuild 2013-12-27

* Sun Jun 23 2013 Matthias Clasen <mclasen@redhat.com> - 1.14.4-3
- Backport another upstream patch for gnome-shell crashes (#954054)

* Fri May 17 2013 Kalev Lember <kalevlember@gmail.com> - 1.14.4-2
- Backport an upstream patch for frequent gnome-shell crashes (#827158)

* Wed May 15 2013 Peter Robinson <pbrobinson@fedoraproject.org> 1.14.4-1
- Update to 1.14.4

* Wed Apr 17 2013 Richard Hughes <rhughes@redhat.com> - 1.14.2-1
- Update to 1.14.2

* Tue Mar 26 2013 Kalev Lember <kalevlember@gmail.com> - 1.14.0-1
- Update to 1.14.0

* Tue Mar 19 2013 Ray Strode <rstrode@redhat.com> 1.13.10-1
- Update to 1.3.10

* Tue Mar  5 2013 Matthias Clasen <mclasen@redhat.com> 1.13.8-1
- Update to 1.13.8

* Thu Feb 21 2013 Bastien Nocera <bnocera@redhat.com> 1.13.6-1
- Update to 1.13.6

* Tue Feb 05 2013 Kalev Lember <kalevlember@gmail.com> - 1.13.4-4
- Backport a patch to use XI2.3, so that clutter keeps working with gtk+ 3.7.8

* Wed Jan 30 2013 Matthias Clasen <mclasen@redhat.com> - 1.13.4-3
- Fix a gnome-shell crash

* Fri Jan 25 2013 Peter Robinson <pbrobinson@fedoraproject.org> 1.13.4-2
- Rebuild for new cogl

* Wed Jan 16 2013 Matthias Clasen <mclasen@redhat.com> - 1.13.4-1
- Update to 1.13.4

* Tue Dec 18 2012 Peter Robinson <pbrobinson@fedoraproject.org> 1.13.2-1
- Update to 1.13.2

* Wed Oct 17 2012 Kalev Lember <kalevlember@gmail.com> - 1.12.2-1
- Update to 1.12.2

* Tue Sep 25 2012 Kalev Lember <kalevlember@gmail.com> - 1.12.0-2
- Obsolete clutter-gtk010 and clutter-sharp as well

* Tue Sep 25 2012 Kalev Lember <kalevlember@gmail.com> - 1.12.0-1
- Update to 1.12.0
- Obsolete pyclutter, -gst and -gtk packages

* Tue Sep 18 2012 Kalev Lember <kalevlember@gmail.com> - 1.11.16-1
- Update to 1.11.16

* Wed Sep 05 2012 Kalev Lember <kalevlember@gmail.com> - 1.11.14-2
- Rebuilt with gobject-introspection 1.33.10 (bgo #682124)

* Mon Sep  3 2012 Peter Robinson <pbrobinson@fedoraproject.org> - 1.11.14-1
- Update to 1.11.12

* Tue Aug 28 2012 Matthias Clasen <mclasen@redhat.com> - 1.11.12-3
- Rebuild against new cogl

* Tue Aug 21 2012 Richard Hughes <hughsient@gmail.com> - 1.11.12-1
- Update to 1.11.12

* Tue Aug  7 2012 Peter Robinson <pbrobinson@fedoraproject.org> - 1.11.10-1
- Update to 1.11.10

* Fri Jul 27 2012 Fedora Release Engineering <rel-eng@lists.fedoraproject.org> - 1.11.8-2
- Rebuilt for https://fedoraproject.org/wiki/Fedora_18_Mass_Rebuild

* Tue Jul 17 2012 Peter Robinson <pbrobinson@fedoraproject.org> - 1.11.8-1
- Update to 1.11.8

* Tue Jun 26 2012 Richard Hughes <hughsient@gmail.com> - 1.11.6-1
- Update to 1.11.6

* Tue Jun  5 2012 Peter Robinson <pbrobinson@fedoraproject.org> - 1.11.4-1
- Update to 1.11.4

* Thu May 10 2012 Kalev Lember <kalevlember@gmail.com> - 1.11.2-1
- Update to 1.11.2

* Thu May 03 2012 Bastien Nocera <bnocera@redhat.com> 1.10.4-2
- Add patches to fix crashes with touch events

* Tue May  1 2012 Peter Robinson <pbrobinson@fedoraproject.org> - 1.10.4-1
- Update to 1.10.4

* Tue Apr 17 2012 Peter Robinson <pbrobinson@fedoraproject.org> - 1.10.2-1
- Update to 1.10.2

* Thu Apr 12 2012 Peter Hutterer <peter.hutterer@redhat.com> 1.10.0-5
- Fix misnamed define to enable XI 2.2 support (#809864)

* Fri Apr 06 2012 Zeeshan Ali <zeenix@redhat.com> - 1.10.0-4
- Include layout fix (Needed by gnome-boxes at least).

* Wed Apr 04 2012 Kalev Lember <kalevlember@gmail.com> - 1.10.0-3
- Obsolete clutter-gesture and clutter-imcontext packages (#809864)

* Thu Mar 29 2012 Kalev Lember <kalevlember@gmail.com> - 1.10.0-2
- Build with xi2.2 support (#803430)
- Enable the GDK backend

* Thu Mar 22 2012 Matthias Clasen <mclasen@redhat.com> - 1.10.0-1
- Update to 1.10.0

* Tue Mar 20 2012 Kalev Lember <kalevlember@gmail.com> - 1.9.16-1
- Update to 1.9.16

* Sat Mar 10 2012 Matthias Clasen <mclasen@redhat.com> - 1.9.14-1
- Update to 1.9.14

* Sat Feb 25 2012 Matthias Clasen <mclasen@redhat.com> - 1.9.12-1
- Update to 1.9.12

* Mon Feb  6 2012 Matthias Clasen <mclasen@redhat.com> - 1.9.10-1
- Update to 1.9.10

* Wed Jan 25 2012 Peter Robinson <pbrobinson@fedoraproject.org> - 1.9.8-1
- 1.9.8 release
- http://ftp.gnome.org/pub/GNOME/sources/clutter/1.9/clutter-1.9.8.news
- Back to tar file releases

* Sat Jan 21 2012 Matthias Clasen <mclasen@redhat.com> - 1.9.7-0.1.20120121
- A snapshot that may now really work with gnome-shell

* Thu Jan 19 2012 Matthias Clasen <mclasen@redhat.com> - 1.9.6-1
- 1.9.6 release
- http://ftp.gnome.org/pub/GNOME/sources/clutter/1.9/clutter-1.9.6.news
- Should work with gnome-shell again

* Wed Jan 18 2012 Peter Robinson <pbrobinson@fedoraproject.org> - 1.9.4-1
- 1.9.4 release
- http://ftp.gnome.org/pub/GNOME/sources/clutter/1.9/clutter-1.9.4.news

* Thu Jan 12 2012 Fedora Release Engineering <rel-eng@lists.fedoraproject.org> - 1.9.2-2
- Rebuilt for https://fedoraproject.org/wiki/Fedora_17_Mass_Rebuild

* Tue Nov 22 2011 Tomas Bzatek <tbzatek@redhat.com> - 1.9.2-1
- Update to 1.9.2

* Wed Oct 26 2011 Fedora Release Engineering <rel-eng@lists.fedoraproject.org> - 1.8.2-2
- Rebuilt for glibc bug#747377

* Mon Oct 17 2011 Peter Robinson <pbrobinson@fedoraproject.org> - 1.8.2-1
- 1.8.2 stable release
- http://ftp.gnome.org/pub/GNOME/sources/clutter/1.8/clutter-1.8.2.news

* Mon Sep 19 2011 Peter Robinson <pbrobinson@fedoraproject.org> - 1.8.0-1
- 1.8.0 stable release
- http://ftp.gnome.org/pub/GNOME/sources/clutter/1.8/clutter-1.8.0.news

* Mon Sep 12 2011 Peter Robinson <pbrobinson@fedoraproject.org> - 1.7.90-1
- Update to 1.7.90
- http://ftp.gnome.org/pub/GNOME/sources/clutter/1.7/clutter-1.7.90.news

* Mon Sep  5 2011 Peter Robinson <pbrobinson@fedoraproject.org> - 1.7.14-1
- Update to 1.7.14

* Wed Aug 31 2011 Matthias Clasen <mclasen@redhat.com> - 1.7.12-1
- Update to 1.7.12

* Thu Aug 18 2011 Matthias Clasen <mclasen@redhat.com> - 1.7.10-1
- Update to 1.7.10

* Mon Aug 15 2011 Peter Robinson <pbrobinson@fedoraproject.org> - 1.7.8-1
- Update to 1.7.8

* Tue Jul 26 2011 Matthias Clasen <mclasen@redhat.com> - 1.7.6-1
- Update to 1.7.6

* Mon Jul  4 2011 Peter Robinson <pbrobinson@fedoraproject.org> - 1.7.4-1
- Update to 1.7.4 devel build
- Build against cogl
- Add patch to fix DSO linking

* Fri Jun 24 2011 Adam Jackson <ajax@redhat.com> 1.6.16-3
- clutter-1.6.16-no-drm-hax.patch: Remove the insane DRM-banging fallback for
  sync to vblank.

* Fri Jun 17 2011 Tomas Bzatek <tbzatek@redhat.com> - 1.6.16-2
- Fix G_CONST_RETURN usage

* Wed Jun 15 2011 Tomas Bzatek <tbzatek@redhat.com> - 1.6.16-1
- Update to 1.6.16

* Tue Apr  5 2011 Matthias Clasen <mclasen@redhat.com> - 1.6.14-1
- Update to 1.6.14

* Mon Apr  4 2011 Matthias Clasen <mclasen@redhat.com> - 1.6.12-1
- Update to 1.6.12

* Mon Mar 21 2011 Matthias Clasen <mclasen@redhat.com> - 1.6.10-1
- Update to 1.6.10

* Mon Mar  7 2011 Matthias Clasen <mclasen@redhat.com> - 1.6.8-1
- Update to 1.6.8

* Wed Mar  2 2011 Matthias Clasen <mclasen@redhat.com> - 1.6.6-2
- Fix icon corruption in gnome-shell

* Mon Feb 21 2011 Peter Robinson <pbrobinson@fedoraproject.org> - 1.6.6-1
- Update to 1.6.6

* Mon Feb 14 2011 Peter Robinson <pbrobinson@fedoraproject.org> - 1.6.4-1
- Update to 1.6.4

* Tue Feb 08 2011 Fedora Release Engineering <rel-eng@lists.fedoraproject.org> - 1.6.2-2
- Rebuilt for https://fedoraproject.org/wiki/Fedora_15_Mass_Rebuild

* Mon Feb  7 2011 Peter Robinson <pbrobinson@fedoraproject.org> - 1.6.2-1
- Update to 1.6.2

* Mon Jan 31 2011 Peter Robinson <pbrobinson@fedoraproject.org> - 1.6.0-1
- Update to 1.6.0

* Mon Jan 24 2011 Peter Robinson <pbrobinson@fedoraproject.org> - 1.5.14-1
- Update to 1.5.14

* Wed Jan 12 2011 Peter Robinson <pbrobinson@fedoraproject.org> - 1.5.12-1
- Update to 1.5.12

* Tue Dec 28 2010 Peter Robinson <pbrobinson@fedoraproject.org> - 1.5.10-1
- Update to 1.5.10

* Mon Dec  6 2010 Peter Robinson <pbrobinson@fedoraproject.org> - 1.5.8-3
- Drop unneeded gtk2-devel builddep that causes issues for gtk3 clutter apps
- Add the independent deps that were pulled in by gtk2-devel

* Mon Nov 29 2010 Owen Taylor <otaylor@redhat.com> - 1.5.8-2
- Update to 1.5.8
- Add cairo-gobject-devel dependency
- Drop unneeded patches

* Mon Nov 22 2010 Dan Williams <dcbw@redhat.com> - 1.4.0-4
- Add a patch cherry-picked from upstream for
  http://bugzilla.clutter-project.org/attachment.cgi?id=2366
  (gnome-shell/mutter hang when gnome-settings-daemon restarts)

* Tue Oct  5 2010 Owen Taylor <otaylor@redhat.com> - 1.4.0-3
- Add a patch cherry-picked from upstream for
  http://bugzilla.clutter-project.org/show_bug.cgi?id=2324
  (gnome-shell crashes on root background changes)

* Wed Sep 29 2010 jkeating - 1.4.0-2
- Rebuilt for gcc bug 634757

* Fri Sep 24 2010 Peter Robinson <pbrobinson@fedoraproject.org> 1.4.0-1
- Update to stable 1.4.0 release

* Wed Sep 22 2010 Matthias Clasen <mclasen@redhat.com> - 1.3.14-1
- Update to 1.3.14

* Tue Sep 21 2010 Matthias Clasen <mclasen@redhat.com> - 1.3.12-2
- Rebuild against newer gobject-introspection

* Tue Aug 31 2010 Colin Walters <walters@verbum.org> - 1.3.12-1
- New upstream

* Thu Jul 15 2010 Colin Walters <walters@verbum.org> - 1.2.10-3
- Rebuild with new gobject-introspection

* Mon Jul 12 2010 Colin Walters <walters@verbum.org> - 1.2.10-2
- Rebuild against new gobject-introspection

* Sun Jul 11 2010 Peter Robinson <pbrobinson@fedoraproject.org> 1.2.10-1
- Update to new upstream stable 1.2.10 release

* Tue Jul  6 2010 Colin Walters <walters@verbum.org> - 1.2.8-4
- Changes to support git snapshot builds

* Thu Jul  1 2010 Mamoru Tasaka <mtasaka@ioa.s.u-tokyo.ac.jp> - 1.2.8-3
- Rebuild for "Incompatible version 1.0 (supported: 1.1)"
  for introspection file

* Thu Jun 10 2010 Colin Walters <walters@verbum.org> 1.2.8-2
- Drop gir-repository dependency, we don't need it anymore 

* Sat May 15 2010 Peter Robinson <pbrobinson@fedoraproject.org> 1.2.8-1
- Update to new upstream stable 1.2.8 release
- Drop upstreamed patches

* Fri Apr 30 2010 Owen Taylor <otaylor@redhat.com> 1.2.6-1
- Update to new upstream stable 1.2.6 release
- Work around Radeon driver problem with color channel confusion.
- Fix Mutter not seeing BufferSwapComplete events and freezing
- Remove incorrect warning message about BufferSwapComplete events

* Sat Mar 20 2010 Peter Robinson <pbrobinson@fedoraproject.org> 1.2.4-1
  Tue Mar 20 2010 --> Tue Mar 16 2010 or Sat Mar 20 2010 or Tue Mar 23 2010 or ....
- Update to new upstream stable 1.2.4 release

* Mon Mar 15 2010 Peter Robinson <pbrobinson@fedoraproject.org> 1.2.2-1
- Update to new upstream stable 1.2.2 release

* Tue Mar  2 2010 Peter Robinson <pbrobinson@fedoraproject.org> 1.2.0-1
- Update to new upstream stable 1.2.0 release

* Sun Feb 28 2010 Peter Robinson <pbrobinson@fedoraproject.org> 1.1.14-1
- Update to 1.1.14

* Thu Feb 11 2010 Peter Robinson <pbrobinson@fedoraproject.org> 1.1.10-2
  Wed Feb 11 2010 --> Wed Feb 10 2010 or Thu Feb 11 2010 or Wed Feb 17 2010 or ....
- Add patch to fix 64bit build 

* Thu Feb 11 2010 Peter Robinson <pbrobinson@fedoraproject.org> 1.1.10-1
  Wed Feb 11 2010 --> Wed Feb 10 2010 or Thu Feb 11 2010 or Wed Feb 17 2010 or ....
- Update to 1.1.10

* Thu Feb  4 2010 Peter Robinson <pbrobinson@fedoraproject.org> 1.1.6-1
- Update to 1.1.6

* Thu Jan  7 2010 Peter Robinson <pbrobinson@fedoraproject.org> 1.0.8-2
- A few minor spec cleanups

* Mon Jan  4 2010 Peter Robinson <pbrobinson@fedoraproject.org> 1.0.8-1
- Update to 1.0.8

* Tue Sep 22 2009 Bastien Nocera <bnocera@redhat.com> 1.0.6-1
- Update to 1.0.6

* Sun Aug 30 2009 Owen Taylor <otaylor@redhat.com> - 1.0.4-1
- Update to 1.0.4, update gobject-introspection requirement

* Fri Aug 14 2009 Bastien Nocera <bnocera@redhat.com> 1.0.2-1
- Update to 1.0.2

* Sun Aug  1 2009 Matthias Clasen <mclasen@redhat.com> 1.0.0-4
- Move ChangeLog to -devel to save some space

* Fri Jul 31 2009 Matthias Clasen <mclasen@redhat.com> 1.0.0-3
- Drop the gir-repository-devel dep, which pulls a bunch of -devel
  onto the live cd

* Wed Jul 29 2009 Bastien Nocera <bnocera@redhat.com> 1.0.0-1
- Update to 1.0.0

* Tue Jul 28 2009 Itamar Reis Peixoto <itamar@ispbrasil.com.br> - 0.9.8-3
- fix bz #507389

* Fri Jul 24 2009 Fedora Release Engineering <rel-eng@lists.fedoraproject.org> - 0.9.8-2
- Rebuilt for https://fedoraproject.org/wiki/Fedora_12_Mass_Rebuild

* Fri Jul 17 2009 Bastien Nocera <bnocera@redhat.com> 0.9.8-1
- Update to 0.9.8

* Fri Jul 17 2009 Bastien Nocera <bnocera@redhat.com> 0.9.6-2
- Patch from Owen Taylor <otaylor@redhat.com> to add gobject-
  introspection support to clutter (#512260)

* Fri Jul 10 2009 Bastien Nocera <bnocera@redhat.com> 0.9.6-1
- Update to 0.9.6

* Sat Jun 20 2009 Bastien Nocera <bnocera@redhat.com> 0.9.4-1
- Update to 0.9.4

* Mon May 18 2009 Bastien Nocera <bnocera@redhat.com> 0.9.2-1
- Update to 0.9.2

* Tue Feb 24 2009 Fedora Release Engineering <rel-eng@lists.fedoraproject.org> - 0.8.6-4
- Rebuilt for https://fedoraproject.org/wiki/Fedora_11_Mass_Rebuild


* Wed Jan 21 2009 Allisson Azevedo <allisson@gmail.com> 0.8.6-3
- Remove noarch from doc subpackage

* Wed Jan 21 2009 Allisson Azevedo <allisson@gmail.com> 0.8.6-2
- Added gtk-doc for cogl
- Created doc subpackage

* Wed Jan 21 2009 Allisson Azevedo <allisson@gmail.com> 0.8.6-1
- Update to 0.8.6

* Mon Oct  6 2008 Allisson Azevedo <allisson@gmail.com> 0.8.2-1
- Update to 0.8.2
- Removed clutter-0.8.0-clutter-fixed.patch

* Sat Sep  6 2008 Allisson Azevedo <allisson@gmail.com> 0.8.0-1
- Update to 0.8.0
- Added clutter-0.8.0-clutter-fixed.patch

* Sat Jun 14 2008 Allisson Azevedo <allisson@gmail.com> 0.6.4-1
- Update to 0.6.4

* Sat May 17 2008 Allisson Azevedo <allisson@gmail.com> 0.6.2-1
- Update to 0.6.2

* Tue Feb 19 2008 Allisson Azevedo <allisson@gmail.com> 0.6.0-1
- Update to 0.6.0

* Mon Feb 18 2008 Fedora Release Engineering <rel-eng@fedoraproject.org> - 0.4.2-2
- Autorebuild for GCC 4.3

* Wed Oct  3 2007 Allisson Azevedo <allisson@gmail.com> 0.4.2-1
- Update to 0.4.2

* Mon Sep  3 2007 Allisson Azevedo <allisson@gmail.com> 0.4.1-1
- Update to 0.4.1

* Sat Jul 21 2007 Allisson Azevedo <allisson@gmail.com> 0.3.1-1
- Update to 0.3.1

* Thu Apr 12 2007 Allisson Azevedo <allisson@gmail.com> 0.2.3-1
- Update to 0.2.3

* Wed Mar 28 2007 Allisson Azevedo <allisson@gmail.com> 0.2.2-4
  Sun Mar 28 2007 --> Sun Mar 25 2007 or Wed Mar 28 2007 or Sun Apr 01 2007 or ....
- Changed buildrequires and requires

* Tue Mar 27 2007 Allisson Azevedo <allisson@gmail.com> 0.2.2-3
  Sun Mar 27 2007 --> Sun Mar 25 2007 or Tue Mar 27 2007 or Sun Apr 01 2007 or ....
- Fix .spec

* Sat Mar 24 2007 Allisson Azevedo <allisson@gmail.com> 0.2.2-2
  Sun Mar 24 2007 --> Sun Mar 18 2007 or Sat Mar 24 2007 or Sun Mar 25 2007 or ....
- Fix .spec

* Fri Mar 23 2007 Allisson Azevedo <allisson@gmail.com> 0.2.2-1
  Sun Mar 23 2007 --> Sun Mar 18 2007 or Fri Mar 23 2007 or Sun Mar 25 2007 or ....
- Initial RPM release
