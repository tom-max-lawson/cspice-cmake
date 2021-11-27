libspkmrg = static_library(
    'spkmrg', [
        'wrdnln.c',
        'cparse_2.c',
        'rdcmd.c',
         ],
   include_directories : includes)

spkmerge = executable(
    'spkmerge', [ 'spkmerge.c', 'main.c' ],
    include_directories : includes,
    link_with : [ libspkmrg, libcsupport, libcspice ],
    dependencies : [ math_dep ],
    install : true)
