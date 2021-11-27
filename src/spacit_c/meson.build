libspacit = static_library(
    'spacit', [
        'getchr.c',
        'ckwss.c',
        'sumpck.c',
        'zzconvtb.c',
        'ckgss.c',
        'getint.c',
        'spat2b.c',
        'pckgss.c',
        'spkgss.c',
        'spab2t.c',
        'pckwss.c',
        'spalog.c',
        'spasum.c',
        'spkwss.c',
        'sumek.c',
        'spardc.c',
        'sumspk.c',
        'sumck.c',
         ],
   include_directories : includes)

spacit = executable(
    'spacit', [ 'spacit.c', 'main.c' ],
    include_directories : includes,
    link_with : [ libspacit, libcsupport, libcspice ],
    dependencies : [ math_dep ],
    install : true)
