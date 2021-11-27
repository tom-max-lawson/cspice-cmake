libtobin = static_library(
    'tobin', [
        'zzconvtb.c',
         ],
   include_directories : includes)

tobin = executable(
    'tobin', [ 'tobin.c', 'main.c' ],
    include_directories : includes,
    link_with : [ libtobin, libcsupport, libcspice ],
    dependencies : [ math_dep ],
    install : true)
