Package: libffi:x64-windows@3.5.2

**Host Environment**

- Host: x64-windows
- Compiler: MSVC 19.50.35718.0
- CMake Version: 3.30.1
-    vcpkg-tool version: 2025-10-16-71538f2694db93da4668782d094768ba74c45991
    vcpkg-scripts version: 7824193852 2025-11-20 (19 hours ago)

**To Reproduce**

`vcpkg install `

**Failure logs**

```
-- Using cached libffi-3.5.2.tar.gz
-- Cleaning sources at C:/dev/vcpkg/buildtrees/libffi/src/libffi-3-c1e5d7d6da.clean. Use --editable to skip cleaning for the packages you specify.
-- Extracting source C:/dev/vcpkg/downloads/libffi-3.5.2.tar.gz
-- Applying patch dll-bindir.diff
-- Using source at C:/dev/vcpkg/buildtrees/libffi/src/libffi-3-c1e5d7d6da.clean
-- Getting CMake variables for x64-windows
-- Loading CMake variables from C:/dev/vcpkg/buildtrees/libffi/cmake-get-vars_ASM_C_CXX-x64-windows.cmake.log
-- Warning: Paths with embedded space may be handled incorrectly by configure:
   C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm A++/vcpkg_installed/x64-windows/x64-windows
   Please move the path to one without whitespaces!
-- Using cached msys2-autoconf-wrapper-20240607-1-any.pkg.tar.zst
-- Using cached msys2-automake-wrapper-20240607-1-any.pkg.tar.zst
-- Using cached msys2-autoconf-archive-2023.02.20-1-any.pkg.tar.zst
-- Using cached msys2-binutils-2.44-1-x86_64.pkg.tar.zst
-- Using cached msys2-libtool-2.5.4-1-x86_64.pkg.tar.zst
-- Using cached msys2-make-4.4.1-2-x86_64.pkg.tar.zst
-- Using cached msys2-which-2.23-4-x86_64.pkg.tar.zst
-- Using cached msys2-bash-5.2.037-2-x86_64.pkg.tar.zst
-- Using cached msys2-coreutils-8.32-5-x86_64.pkg.tar.zst
-- Using cached msys2-file-5.46-2-x86_64.pkg.tar.zst
-- Using cached msys2-gawk-5.3.2-1-x86_64.pkg.tar.zst
-- Using cached msys2-grep-1~3.0-7-x86_64.pkg.tar.zst
-- Using cached msys2-gzip-1.14-1-x86_64.pkg.tar.zst
-- Using cached msys2-diffutils-3.12-1-x86_64.pkg.tar.zst
-- Using cached msys2-pkgconf-2.4.3-1-x86_64.pkg.tar.zst
-- Using cached msys2-sed-4.9-1-x86_64.pkg.tar.zst
-- Using cached msys2-msys2-runtime-3.6.2-2-x86_64.pkg.tar.zst
-- Using cached msys2-autoconf2.72-2.72-3-any.pkg.tar.zst
-- Using cached msys2-automake1.16-1.16.5-1-any.pkg.tar.zst
-- Using cached msys2-automake1.17-1.17-1-any.pkg.tar.zst
-- Using cached msys2-libiconv-1.18-1-x86_64.pkg.tar.zst
-- Using cached msys2-libintl-0.22.5-1-x86_64.pkg.tar.zst
-- Using cached msys2-zlib-1.3.1-1-x86_64.pkg.tar.zst
-- Using cached msys2-findutils-4.10.0-2-x86_64.pkg.tar.zst
-- Using cached msys2-tar-1.35-2-x86_64.pkg.tar.zst
-- Using cached msys2-gmp-6.3.0-1-x86_64.pkg.tar.zst
-- Using cached msys2-gcc-libs-13.3.0-1-x86_64.pkg.tar.zst
-- Using cached msys2-libbz2-1.0.8-4-x86_64.pkg.tar.zst
-- Using cached msys2-liblzma-5.8.1-1-x86_64.pkg.tar.zst
-- Using cached msys2-libzstd-1.5.7-1-x86_64.pkg.tar.zst
-- Using cached msys2-libreadline-8.2.013-1-x86_64.pkg.tar.zst
-- Using cached msys2-mpfr-4.2.2-1-x86_64.pkg.tar.zst
-- Using cached msys2-libpcre-8.45-5-x86_64.pkg.tar.zst
-- Using cached msys2-m4-1.4.19-2-x86_64.pkg.tar.zst
-- Using cached msys2-perl-5.38.4-2-x86_64.pkg.tar.zst
-- Using cached msys2-ncurses-6.5.20240831-2-x86_64.pkg.tar.zst
-- Using cached msys2-libxcrypt-4.4.38-1-x86_64.pkg.tar.zst
-- Using msys root at C:/dev/vcpkg/downloads/tools/msys2/8392cd453c24d30d
-- Configuring x64-windows-dbg
CMake Error at scripts/cmake/vcpkg_execute_required_process.cmake:127 (message):
    Command failed: C:/dev/vcpkg/downloads/tools/msys2/8392cd453c24d30d/usr/bin/bash.exe --noprofile --norc --debug -c "V=1 CPP='compile cl.exe -E' CC='compile cl.exe' CXX='compile cl.exe' CC_FOR_BUILD='compile cl.exe' CPP_FOR_BUILD='compile cl.exe -E' CXX_FOR_BUILD='compile cl.exe' RC='windres-rc rc.exe' WINDRES='windres-rc rc.exe' AR='ar-lib lib.exe' LD='link.exe -verbose' RANLIB=':' STRIP=': STRIP-disabled' NM='dumpbin.exe -symbols -headers' DLLTOOL='link.exe -verbose -dll' CCAS='C:/dev/vcpkg/downloads/tools/clang/clang-15.0.6/bin/clang.exe --target=x86_64-pc-windows-msvc -c' AS='C:/dev/vcpkg/downloads/tools/clang/clang-15.0.6/bin/clang.exe --target=x86_64-pc-windows-msvc -c' ./../src/libffi-3-c1e5d7d6da.clean/configure \"--host=x86_64-pc-mingw32\" \"--build=x86_64-pc-mingw32\" \"--enable-portable-binary\" \"--disable-docs\" \"--disable-multi-os-directory\" \"CFLAGS=${CFLAGS} -DFFI_BUILDING_DLL\" \"CCAS=msvcc.sh\" \"CCASFLAGS=${CCASFLAGS} -m64\" \"lt_cv_deplibs_check_method=pass_all\" \"gl_cv_double_slash_root=yes\" \"ac_cv_func_memmove=yes\" \"ac_cv_func_memset=yes\" \"--prefix=/C/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm A++/vcpkg_installed/x64-windows/x64-windows/debug\" \"--bindir=\\${prefix}/../tools/libffi/debug/bin\" \"--sbindir=\\${prefix}/../tools/libffi/debug/sbin\" \"--libdir=\\${prefix}/lib\" \"--includedir=\\${prefix}/../include\" \"--mandir=\\${prefix}/share/libffi\" \"--docdir=\\${prefix}/share/libffi\" \"--datarootdir=\\${prefix}/share/libffi\" \"--enable-shared\" \"--disable-static\""
    Working Directory: C:/dev/vcpkg/buildtrees/libffi/x64-windows-dbg
    Error code: 77
    See logs for more information:
      C:\dev\vcpkg\buildtrees\libffi\config-x64-windows-dbg-config.log
      C:\dev\vcpkg\buildtrees\libffi\config-x64-windows-dbg-out.log
      C:\dev\vcpkg\buildtrees\libffi\config-x64-windows-dbg-err.log

Call Stack (most recent call first):
  C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm A++/vcpkg_installed/x64-windows/x64-windows/share/vcpkg-make/vcpkg_make.cmake:41 (vcpkg_execute_required_process)
  C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm A++/vcpkg_installed/x64-windows/x64-windows/share/vcpkg-make/vcpkg_make.cmake:339 (vcpkg_run_shell)
  C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm A++/vcpkg_installed/x64-windows/x64-windows/share/vcpkg-make/vcpkg_make_configure.cmake:109 (vcpkg_make_run_configure)
  buildtrees/versioning_/versions/libffi/7af0617a77238936f200b50b6f1797e280a43fbf/portfile.cmake:42 (vcpkg_make_configure)
  scripts/ports.cmake:206 (include)



```

<details><summary>C:\dev\vcpkg\buildtrees\libffi\config-x64-windows-dbg-err.log</summary>

```
configure: error: in '/c/dev/vcpkg/buildtrees/libffi/x64-windows-dbg':
configure: error: C compiler cannot create executables
See 'config.log' for more details
```
</details>

<details><summary>C:\dev\vcpkg\buildtrees\libffi\config-x64-windows-dbg-out.log</summary>

```
checking build system type... x86_64-pc-mingw32
checking host system type... x86_64-pc-mingw32
checking target system type... x86_64-pc-mingw32
checking for gsed... sed
checking for a BSD-compatible install... /usr/bin/install -c
checking whether sleep supports fractional seconds... yes
checking filesystem timestamp resolution... 0.01
checking whether build environment is sane... yes
checking for a race-free mkdir -p... /usr/bin/mkdir -p
checking for gawk... gawk
checking whether make sets $(MAKE)... yes
checking whether make supports nested variables... yes
checking xargs -n works... yes
checking for x86_64-pc-mingw32-gcc... compile cl.exe
checking whether the C compiler works... no
```
</details>

<details><summary>C:\dev\vcpkg\buildtrees\libffi\config-x64-windows-dbg-config.log</summary>

```
This file contains any messages produced by compilers while
running configure, to aid debugging if configure makes a mistake.

It was created by libffi configure 3.5.2, which was
generated by GNU Autoconf 2.72.  Invocation command line was

  $ ./../src/libffi-3-c1e5d7d6da.clean/configure --host=x86_64-pc-mingw32 --build=x86_64-pc-mingw32 --enable-portable-binary --disable-docs --disable-multi-os-directory 'CFLAGS=-Xcompiler -nologo -Xcompiler -DWIN32 -Xcompiler -D_WINDOWS -Xcompiler -utf-8 -Xcompiler -MP -Xcompiler -MDd -Xcompiler -Z7 -Xcompiler -Ob0 -Xcompiler -Od -Xcompiler -RTC1 -DFFI_BUILDING_DLL' CCAS=msvcc.sh 'CCASFLAGS= -m64' lt_cv_deplibs_check_method=pass_all gl_cv_double_slash_root=yes ac_cv_func_memmove=yes ac_cv_func_memset=yes '--prefix=/C/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm A++/vcpkg_installed/x64-windows/x64-windows/debug' '--bindir=${prefix}/../tools/libffi/debug/bin' '--sbindir=${prefix}/../tools/libffi/debug/sbin' '--libdir=${prefix}/lib' '--includedir=${prefix}/../include' '--mandir=${prefix}/share/libffi' '--docdir=${prefix}/share/libffi' '--datarootdir=${prefix}/share/libffi' --enable-shared --disable-static

## --------- ##
## Platform. ##
## --------- ##

hostname = Tutek-Komputer
uname -m = x86_64
uname -r = 3.6.2-a9cfe9f5.x86_64
uname -s = MSYS_NT-10.0-19044
uname -v = 2025-06-03 09:09 UTC

/usr/bin/uname -p = unknown
/bin/uname -X     = unknown

/bin/arch              = x86_64
/usr/bin/arch -k       = unknown
/usr/convex/getsysinfo = unknown
/usr/bin/hostinfo      = unknown
/bin/machine           = unknown
/usr/bin/oslevel       = unknown
/bin/universe          = unknown

PATH: /c/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm A++/vcpkg_installed/x64-windows/x64-windows/share/vcpkg-make/wrappers/
PATH: /c/Program Files/Microsoft Visual Studio/18/Community/VC/Tools/MSVC/14.50.35717/bin/HostX64/x64/
PATH: /c/Program Files/Microsoft Visual Studio/18/Community/Common7/IDE/VC/VCPackages/
PATH: /c/Program Files/Microsoft Visual Studio/18/Community/Common7/IDE/CommonExtensions/Microsoft/TestWindow/
PATH: /c/Program Files/Microsoft Visual Studio/18/Community/Common7/IDE/CommonExtensions/Microsoft/TeamFoundation/Team Explorer/
PATH: /c/Program Files/Microsoft Visual Studio/18/Community/MSBuild/Current/bin/Roslyn/
PATH: /c/Program Files (x86)/Microsoft SDKs/Windows/v10.0A/bin/NETFX 4.8 Tools/x64/
PATH: /c/Program Files/Microsoft Visual Studio/18/Community/Common7/IDE/CommonExtensions/Microsoft/FSharp/Tools/
PATH: /c/Program Files/Microsoft Visual Studio/18/Community/Team Tools/DiagnosticsHub/Collector/
PATH: /c/Program Files/Microsoft Visual Studio/18/Community/Common7/IDE/Extensions/Microsoft/CodeCoverage.Console/
PATH: /c/Program Files (x86)/Windows Kits/10/bin/10.0.26100.0/x64/
PATH: /c/Program Files (x86)/Windows Kits/10/bin/x64/
PATH: /c/Program Files/Microsoft Visual Studio/18/Community/MSBuild/Current/Bin/amd64/
PATH: /c/Windows/Microsoft.NET/Framework64/v4.0.30319/
PATH: /c/Program Files/Microsoft Visual Studio/18/Community/Common7/IDE/
PATH: /c/Program Files/Microsoft Visual Studio/18/Community/Common7/Tools/
PATH: /c/dev/vcpkg/downloads/tools/powershell-core-7.5.3-windows/
PATH: /usr/bin/
PATH: /c/Windows/system32/
PATH: /c/Windows/
PATH: /c/Windows/system32/Wbem/
PATH: /c/Windows/system32/WindowsPowerShell/v1.0/
PATH: /c/Windows/system32/OpenSSH/
PATH: /c/Program Files/Microsoft Visual Studio/18/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/
PATH: /c/Program Files/Microsoft Visual Studio/18/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/Ninja/
PATH: /c/Program Files/Microsoft Visual Studio/18/Community/Common7/IDE/VC/Linux/bin/ConnectionManagerExe/
PATH: /c/Program Files/Microsoft Visual Studio/18/Community/VC/vcpkg/
PATH: /c/dev/vcpkg/downloads/tools/ninja/1.13.1-windows/
PATH: /c/dev/vcpkg/buildtrees/libffi/src/libffi-3-c1e5d7d6da.clean/


## ----------- ##
## Core tests. ##
## ----------- ##

configure:3053: looking for aux files: ltmain.sh compile missing install-sh config.guess config.sub
configure:3066:  trying ./../src/libffi-3-c1e5d7d6da.clean/
configure:3095:   ./../src/libffi-3-c1e5d7d6da.clean/ltmain.sh found
configure:3095:   ./../src/libffi-3-c1e5d7d6da.clean/compile found
configure:3095:   ./../src/libffi-3-c1e5d7d6da.clean/missing found
configure:3077:   ./../src/libffi-3-c1e5d7d6da.clean/install-sh found
configure:3095:   ./../src/libffi-3-c1e5d7d6da.clean/config.guess found
configure:3095:   ./../src/libffi-3-c1e5d7d6da.clean/config.sub found
configure:3222: checking build system type
configure:3238: result: x86_64-pc-mingw32
configure:3258: checking host system type
configure:3273: result: x86_64-pc-mingw32
configure:3293: checking target system type
configure:3308: result: x86_64-pc-mingw32
configure:3407: checking for gsed
configure:3444: result: sed
configure:3473: checking for a BSD-compatible install
configure:3547: result: /usr/bin/install -c
configure:3558: checking whether sleep supports fractional seconds
configure:3574: result: yes
configure:3577: checking filesystem timestamp resolution
configure:3712: result: 0.01
configure:3717: checking whether build environment is sane
configure:3758: result: yes
configure:3925: checking for a race-free mkdir -p
configure:3968: result: /usr/bin/mkdir -p
configure:3975: checking for gawk
configure:3996: found /usr/bin/gawk
configure:4008: result: gawk
configure:4019: checking whether make sets $(MAKE)
configure:4043: result: yes
configure:4069: checking whether make supports nested variables
configure:4088: result: yes
configure:4102: checking xargs -n works
configure:4118: result: yes
configure:4244: checking for x86_64-pc-mingw32-gcc
configure:4277: result: compile cl.exe
configure:4682: checking for C compiler version
configure:4691: compile cl.exe --version >&5
Microsoft (R) C/C++ wersja kompilatora optymalizującego 19.50.35718 dla x64
Copyright (C) Microsoft Corporation. Wszystkie prawa zastrzeżone.

cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „--version”
cl : Wiersz polecenia error D8003 : brakująca nazwa pliku źródłowego
configure:4702: $? = 2
configure:4691: compile cl.exe -v >&5
Microsoft (R) C/C++ wersja kompilatora optymalizującego 19.50.35718 dla x64
Copyright (C) Microsoft Corporation. Wszystkie prawa zastrzeżone.

cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-v”
cl : Wiersz polecenia error D8003 : brakująca nazwa pliku źródłowego
configure:4702: $? = 2
configure:4691: compile cl.exe -V >&5
Microsoft (R) C/C++ wersja kompilatora optymalizującego 19.50.35718 dla x64
Copyright (C) Microsoft Corporation. Wszystkie prawa zastrzeżone.

cl : Wiersz polecenia error D8004 : "/V" wymaga argumentu
configure:4702: $? = 2
configure:4691: compile cl.exe -qversion >&5
Microsoft (R) C/C++ wersja kompilatora optymalizującego 19.50.35718 dla x64
Copyright (C) Microsoft Corporation. Wszystkie prawa zastrzeżone.

cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-qversion”
cl : Wiersz polecenia error D8003 : brakująca nazwa pliku źródłowego
configure:4702: $? = 2
configure:4691: compile cl.exe -version >&5
Microsoft (R) C/C++ wersja kompilatora optymalizującego 19.50.35718 dla x64
Copyright (C) Microsoft Corporation. Wszystkie prawa zastrzeżone.

cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-version”
cl : Wiersz polecenia error D8003 : brakująca nazwa pliku źródłowego
configure:4702: $? = 2
configure:4722: checking whether the C compiler works
configure:4744: compile cl.exe -Xcompiler -nologo -Xcompiler -DWIN32 -Xcompiler -D_WINDOWS -Xcompiler -utf-8 -Xcompiler -MP -Xcompiler -MDd -Xcompiler -Z7 -Xcompiler -Ob0 -Xcompiler -Od -Xcompiler -RTC1 -DFFI_BUILDING_DLL  -Xlinker -Xlinker -Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\ A++/vcpkg_installed/x64-windows/x64-windows/debug/lib -Xlinker -Xlinker -Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\ A++/vcpkg_installed/x64-windows/x64-windows/debug/lib/manual-link -Xlinker -Xlinker -Xlinker -machine:x64 -Xlinker -Xlinker -Xlinker -nologo -Xlinker -Xlinker -Xlinker -debug -Xlinker -Xlinker -Xlinker -INCREMENTAL conftest.c -lkernel32 -luser32 -lgdi32 -lwinspool -lshell32 -lole32 -loleaut32 -lcomdlg32 -ladvapi32 >&5
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib/manual-link", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib/manual-link", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
conftest.c
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib/manual-link", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib/manual-link", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib/manual-link", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xcompiler”
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib/manual-link", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib/manual-link", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib/manual-link", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib/manual-link", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9002 : ignorowanie nieznanej opcji „-Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\”
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib/manual-link", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib/manual-link", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib/manual-link", przyjmuje się plik obiektu
cl : Wiersz polecenia warning D9024 : nierozpoznany typ pliku źródłowego "A++/vcpkg_installed/x64-windows/x64-windows/debug/lib/manual-link", przyjmuje się plik obiektu
LINK : warning LNK4044: nierozpoznana opcja „/Xlinker”; zignorowano
LINK : warning LNK4044: nierozpoznana opcja „/Xlinker”; zignorowano
LINK : warning LNK4044: nierozpoznana opcja „/Xlinker”; zignorowano
LINK : warning LNK4044: nierozpoznana opcja „/Xlinker”; zignorowano
LINK : warning LNK4044: nierozpoznana opcja „/Xlinker”; zignorowano
LINK : warning LNK4044: nierozpoznana opcja „/Xlinker”; zignorowano
LINK : fatal error LNK1104: nie można otworzyć pliku „A++\vcpkg_installed\x64-windows\x64-windows\debug\lib.obj”
configure:4748: $? = 2
configure:4789: result: no
configure: failed program was:
| /* confdefs.h */
| #define PACKAGE_NAME "libffi"
| #define PACKAGE_TARNAME "libffi"
| #define PACKAGE_VERSION "3.5.2"
| #define PACKAGE_STRING "libffi 3.5.2"
| #define PACKAGE_BUGREPORT "http://github.com/libffi/libffi/issues"
| #define PACKAGE_URL ""
| #define PACKAGE "libffi"
| #define VERSION "3.5.2"
| /* end confdefs.h.  */
| 
| int
| main (void)
| {
| 
|   ;
|   return 0;
| }
configure:4794: error: in '/c/dev/vcpkg/buildtrees/libffi/x64-windows-dbg':
configure:4796: error: C compiler cannot create executables
See 'config.log' for more details

## ---------------- ##
## Cache variables. ##
## ---------------- ##

ac_cv_build=x86_64-pc-mingw32
ac_cv_env_CCASFLAGS_set=set
ac_cv_env_CCASFLAGS_value=' -m64'
ac_cv_env_CCAS_set=set
ac_cv_env_CCAS_value=msvcc.sh
ac_cv_env_CPPFLAGS_set=
ac_cv_env_CPPFLAGS_value=
ac_cv_env_CXXCPP_set=
ac_cv_env_CXXCPP_value=
ac_cv_env_LT_SYS_LIBRARY_PATH_set=
ac_cv_env_LT_SYS_LIBRARY_PATH_value=
ac_cv_env_WASM64_MEMORY64_set=
ac_cv_env_WASM64_MEMORY64_value=
ac_cv_env_build_alias_set=set
ac_cv_env_build_alias_value=x86_64-pc-mingw32
ac_cv_env_host_alias_set=set
ac_cv_env_host_alias_value=x86_64-pc-mingw32
ac_cv_env_target_alias_set=
ac_cv_env_target_alias_value=
ac_cv_func_memmove=yes
ac_cv_func_memset=yes
ac_cv_host=x86_64-pc-mingw32
ac_cv_path_ax_enable_builddir_sed=sed
ac_cv_path_install='/usr/bin/install -c'
ac_cv_path_mkdir=/usr/bin/mkdir
ac_cv_prog_AWK=gawk
ac_cv_prog_CC='compile cl.exe'
ac_cv_prog_make_make_set=yes
ac_cv_target=x86_64-pc-mingw32
am_cv_filesystem_timestamp_resolution=0.01
am_cv_make_support_nested_variables=yes
am_cv_sleep_fractional_seconds=yes
am_cv_xargs_n_works=yes
gl_cv_double_slash_root=yes
lt_cv_deplibs_check_method=pass_all

## ----------------- ##
## Output variables. ##
## ----------------- ##

ACLOCAL='${SHELL} '\''/c/dev/vcpkg/buildtrees/libffi/src/libffi-3-c1e5d7d6da.clean/missing'\'' aclocal-1.17'
AMDEPBACKSLASH=''
AMDEP_FALSE=''
AMDEP_TRUE=''
AMTAR='$${TAR-tar}'
AM_BACKSLASH='\'
AM_DEFAULT_V=''
AM_DEFAULT_VERBOSITY='1'
AM_LTLDFLAGS=''
AM_RUNTESTFLAGS=''
AM_V=''
AR='ar-lib lib.exe'
AUTOCONF='${SHELL} '\''/c/dev/vcpkg/buildtrees/libffi/src/libffi-3-c1e5d7d6da.clean/missing'\'' autoconf'
AUTOHEADER='${SHELL} '\''/c/dev/vcpkg/buildtrees/libffi/src/libffi-3-c1e5d7d6da.clean/missing'\'' autoheader'
AUTOMAKE='${SHELL} '\''/c/dev/vcpkg/buildtrees/libffi/src/libffi-3-c1e5d7d6da.clean/missing'\'' automake-1.17'
AWK='gawk'
BUILD_DOCS_FALSE=''
BUILD_DOCS_TRUE=''
CC='compile cl.exe'
CCAS='msvcc.sh'
CCASDEPMODE=''
CCASFLAGS=' -m64'
CCDEPMODE=''
CFLAGS='-Xcompiler -nologo -Xcompiler -DWIN32 -Xcompiler -D_WINDOWS -Xcompiler -utf-8 -Xcompiler -MP -Xcompiler -MDd -Xcompiler -Z7 -Xcompiler -Ob0 -Xcompiler -Od -Xcompiler -RTC1 -DFFI_BUILDING_DLL'
CPPFLAGS=''
CSCOPE='cscope'
CTAGS='ctags'
CXX='compile cl.exe'
CXXCPP=''
CXXDEPMODE=''
CXXFLAGS='-Xcompiler -nologo -Xcompiler -DWIN32 -Xcompiler -D_WINDOWS -Xcompiler -utf-8 -Xcompiler -GR -Xcompiler -EHsc -Xcompiler -MP -Xcompiler -MDd -Xcompiler -Z7 -Xcompiler -Ob0 -Xcompiler -Od -Xcompiler -RTC1'
CYGPATH_W='cygpath -w'
DEFS=''
DEPDIR=''
DLLTOOL='link.exe -verbose -dll'
DSYMUTIL=''
DUMPBIN=''
ECHO_C=''
ECHO_N='-n'
ECHO_T=''
EGREP=''
ETAGS='etags'
EXEEXT=''
FFI_DEBUG_FALSE=''
FFI_DEBUG_TRUE=''
FFI_EXEC_TRAMPOLINE_TABLE=''
FFI_EXEC_TRAMPOLINE_TABLE_FALSE=''
FFI_EXEC_TRAMPOLINE_TABLE_TRUE=''
FFI_VERSION_NUMBER='30502'
FFI_VERSION_STRING='3.5.2'
FGREP=''
FILECMD=''
GREP=''
HAVE_LONG_DOUBLE=''
HAVE_LONG_DOUBLE_VARIANT=''
INSTALL_DATA='${INSTALL} -m 644'
INSTALL_PROGRAM='${INSTALL}'
INSTALL_SCRIPT='${INSTALL}'
INSTALL_STRIP_PROGRAM='$(install_sh) -c -s'
LD='link.exe -verbose'
LDFLAGS='-Xlinker -Xlinker -Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\ A++/vcpkg_installed/x64-windows/x64-windows/debug/lib -Xlinker -Xlinker -Xlinker-LIBPATH:C:/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm\ A++/vcpkg_installed/x64-windows/x64-windows/debug/lib/manual-link -Xlinker -Xlinker -Xlinker -machine:x64 -Xlinker -Xlinker -Xlinker -nologo -Xlinker -Xlinker -Xlinker -debug -Xlinker -Xlinker -Xlinker -INCREMENTAL'
LIBFFI_BUILD_VERSIONED_SHLIB_FALSE=''
LIBFFI_BUILD_VERSIONED_SHLIB_GNU_FALSE=''
LIBFFI_BUILD_VERSIONED_SHLIB_GNU_TRUE=''
LIBFFI_BUILD_VERSIONED_SHLIB_SUN_FALSE=''
LIBFFI_BUILD_VERSIONED_SHLIB_SUN_TRUE=''
LIBFFI_BUILD_VERSIONED_SHLIB_TRUE=''
LIBOBJS=''
LIBS='-lkernel32 -luser32 -lgdi32 -lwinspool -lshell32 -lole32 -loleaut32 -lcomdlg32 -ladvapi32'
LIBTOOL=''
LIPO=''
LN_S=''
LTLIBOBJS=''
LT_SYS_LIBRARY_PATH=''
MAINT=''
MAINTAINER_MODE_FALSE=''
MAINTAINER_MODE_TRUE=''
MAKEINFO='${SHELL} '\''/c/dev/vcpkg/buildtrees/libffi/src/libffi-3-c1e5d7d6da.clean/missing'\'' makeinfo'
MANIFEST_TOOL=''
MKDIR_P='/usr/bin/mkdir -p'
NM='dumpbin.exe -symbols -headers'
NMEDIT=''
OBJDUMP=''
OBJEXT=''
OPT_LDFLAGS=''
OTOOL64=''
OTOOL=''
PACKAGE='libffi'
PACKAGE_BUGREPORT='http://github.com/libffi/libffi/issues'
PACKAGE_NAME='libffi'
PACKAGE_STRING='libffi 3.5.2'
PACKAGE_TARNAME='libffi'
PACKAGE_URL=''
PACKAGE_VERSION='3.5.2'
PATH_SEPARATOR=':'
PRTDIAG=''
RANLIB=':'
READELF=''
SECTION_LDFLAGS=''
SED=''
SET_MAKE=''
SHELL='/bin/sh'
STRIP=': STRIP-disabled'
TARGET=''
TARGETDIR=''
TARGET_OBJ=''
TESTSUBDIR_FALSE=''
TESTSUBDIR_TRUE=''
VERSION='3.5.2'
WASM64_MEMORY64=''
ac_ct_AR=''
ac_ct_CC=''
ac_ct_CXX=''
ac_ct_DUMPBIN=''
ac_ct_READELF=''
am__EXEEXT_FALSE=''
am__EXEEXT_TRUE=''
am__fastdepCCAS_FALSE=''
am__fastdepCCAS_TRUE=''
am__fastdepCC_FALSE=''
am__fastdepCC_TRUE=''
am__fastdepCXX_FALSE=''
am__fastdepCXX_TRUE=''
am__include=''
am__isrc=' -I$(srcdir)'
am__leading_dot='.'
am__nodep=''
am__quote=''
am__rm_f_notfound=''
am__tar='$${TAR-tar} chof - "$$tardir"'
am__untar='$${TAR-tar} xf -'
am__xargs_n='xargs -n'
ax_enable_builddir_sed='sed'
bindir='${prefix}/../tools/libffi/debug/bin'
build='x86_64-pc-mingw32'
build_alias='x86_64-pc-mingw32'
build_cpu='x86_64'
build_os='mingw32'
build_vendor='pc'
datadir='${datarootdir}'
datarootdir='${prefix}/share/libffi'
docdir='${prefix}/share/libffi'
dvidir='${docdir}'
exec_prefix='NONE'
host='x86_64-pc-mingw32'
host_alias='x86_64-pc-mingw32'
host_cpu='x86_64'
host_os='mingw32'
host_vendor='pc'
htmldir='${docdir}'
includedir='${prefix}/../include'
infodir='${datarootdir}/info'
install_sh='${SHELL} /c/dev/vcpkg/buildtrees/libffi/src/libffi-3-c1e5d7d6da.clean/install-sh'
libdir='${prefix}/lib'
libexecdir='${exec_prefix}/libexec'
localedir='${datarootdir}/locale'
localstatedir='${prefix}/var'
mandir='${prefix}/share/libffi'
mkdir_p='$(MKDIR_P)'
oldincludedir='/usr/include'
pdfdir='${docdir}'
prefix='/C/Users/tutekxd123/source/repos/Algorytm-A-/Algorytm A++/vcpkg_installed/x64-windows/x64-windows/debug'
program_transform_name='s,x,x,'
psdir='${docdir}'
runstatedir='${localstatedir}/run'
sbindir='${prefix}/../tools/libffi/debug/sbin'
sharedstatedir='${prefix}/com'
sys_symbol_underscore=''
sysconfdir='${prefix}/etc'
target='x86_64-pc-mingw32'
target_alias='x86_64-pc-mingw32'
target_cpu='x86_64'
target_os='mingw32'
target_vendor='pc'
tmake_file=''
toolexecdir=''
toolexeclibdir=''

## ----------- ##
## confdefs.h. ##
## ----------- ##

/* confdefs.h */
#define PACKAGE_NAME "libffi"
#define PACKAGE_TARNAME "libffi"
#define PACKAGE_VERSION "3.5.2"
#define PACKAGE_STRING "libffi 3.5.2"
#define PACKAGE_BUGREPORT "http://github.com/libffi/libffi/issues"
#define PACKAGE_URL ""
#define PACKAGE "libffi"
#define VERSION "3.5.2"

configure: exit 77
```
</details>

**Additional context**

<details><summary>vcpkg.json</summary>

```
{
  "$schema": "https://raw.githubusercontent.com/microsoft/vcpkg-tool/main/docs/vcpkg.schema.json",
  "dependencies": [
    "glaze",
    "boost"
  ],
  "builtin-baseline": "f391908e74c7ecaf910fbb006e6edd512094fa7f"
}

```
</details>
