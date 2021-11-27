libmkspk = static_library(
    'mkspk', [
        'redbuf.c',
        'setup.c',
        'chckdo.c',
        'tle2spk.c',
        'reorbd.c',
        'parsdo.c',
        'setelm.c',
        'cmlarg.c',
         ],
   include_directories : includes)

mkspk = executable(
    'mkspk', [ 'mkspk.c', 'main.c' ],
    include_directories : includes,
    link_with : [ libmkspk, libcsupport, libcspice ],
    dependencies : [ math_dep ],
    install : true)
