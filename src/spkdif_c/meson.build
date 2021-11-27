libspkdif = static_library(
    'spkdif', [
        'ldklst.c',
        'stdiff.c',
        'dr2str.c',
        'chwcml.c',
        'getsta.c',
         ],
   include_directories : includes)

spkdiff = executable(
    'spkdiff', [ 'spkdiff.c', 'main.c' ],
    include_directories : includes,
    link_with : [ libspkdif, libcsupport, libcspice ],
    dependencies : [ math_dep ],
    install : true)
