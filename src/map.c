



int do_map(char *indent) {

    fprintf( ptr, "MAP\n" );
    

    fprintf( ptr, "ANGLE %s%s\n", indent, *data );

    /* FIXME DO CONFIG
CONFIG [key] [value]
*/

    fprintf( ptr, "DATAPATTERN %s%s\n", indent, data.datapattern );
    fprintf( ptr, "DEBUG %s%s\n", indent, data.debug );
    fprintf( ptr, "DEFRESOLUTION %s\n", indent, data.debug );

|scalebar_id|shapepath|size|status|symbolset|templatepattern|units|web_id

    fprintf( ptr, "EXTENT %s\n", indent, data.extent ); // fixme array
    fprintf( ptr, "FONTSET %s\n", indent, data.fontset );
    fprintf( ptr, "IMAGECOLOR %s\n", indent, data.imagecolor ); // fixme array
    //dfprintf( ptr, "IMAGEQUALITY %s\n", indent, data.imagequality );
    fprintf( ptr, "IMAGETYPE %s\n", indent, data.imagetype );
    //dfprintf( ptr, "INTERLACE %s\n", indent, data.interlace );

do layer
do legend
    fprintf( ptr, "MAXSIZE %s\n", indent, data.maxsize );
    fprintf( ptr, "NAME %s\n", indent, data.name );

do projection
do querymap
do reference

    fprintf( ptr, "RESOLUTION %s\n", indent, data.resolution );
    fprintf( ptr, "SCALEDENOM %s\n", indent, data.scaledenom );

do scalebar

    fprintf( ptr, "SHAPEPATH %s\n", indent, data.shapepath );
    fprintf( ptr, "SIZE %s\n", indent, data.size );  // fixme array
    fprintf( ptr, "STATUS %s\n", indent, data.status );
    fprintf( ptr, "SYMBOLSET %s\n", indent, data.debug );

do symbol

    fprintf( ptr, "TEMPLATEPATTERN %s\n", indent, data.debug );
    //dfprintf( ptr, "TRANSPARENT %s\n", indent, data.debug );
    fprintf( ptr, "UNITS %s\n", indent, data.debug );

do web

}





