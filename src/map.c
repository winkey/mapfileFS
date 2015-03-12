



int do_map(buffer *buf) {


    buffer_printf(buf, "MAP\n" );
    buf->indent++;

    buffer_printf(buf, "ANGLE %s%s\n", indent, *data );

    /* FIXME DO CONFIG
CONFIG [key] [value]
*/

    buffer_printf(buf, "DATAPATTERN %s%s\n", indent, data.datapattern );
    buffer_printf(buf, "DEBUG %s%s\n", indent, data.debug );
    buffer_printf(buf, "DEFRESOLUTION %s\n", indent, data.debug );

|scalebar_id|shapepath|size|status|symbolset|templatepattern|units|web_id

    buffer_printf(buf, "EXTENT %s\n", indent, data.extent ); // fixme array
    buffer_printf(buf, "FONTSET %s\n", indent, data.fontset );
    buffer_printf(buf, "IMAGECOLOR %s\n", indent, data.imagecolor ); // fixme array
    //dbuffer_printf(buf, "IMAGEQUALITY %s\n", indent, data.imagequality );
    buffer_printf(buf, "IMAGETYPE %s\n", indent, data.imagetype );
    //dbuffer_printf(buf, "INTERLACE %s\n", indent, data.interlace );

do layer
do legend
    buffer_printf(buf, "MAXSIZE %s\n", indent, data.maxsize );
    buffer_printf(buf, "NAME %s\n", indent, data.name );

do projection
do querymap
do reference

    buffer_printf(buf, "RESOLUTION %s\n", indent, data.resolution );
    buffer_printf(buf, "SCALEDENOM %s\n", indent, data.scaledenom );

do scalebar

    buffer_printf(buf, "SHAPEPATH %s\n", indent, data.shapepath );
    buffer_printf(buf, "SIZE %s\n", indent, data.size );  // fixme array
    buffer_printf(buf, "STATUS %s\n", indent, data.status );
    buffer_printf(buf, "SYMBOLSET %s\n", indent, data.debug );

do symbol

    buffer_printf(buf, "TEMPLATEPATTERN %s\n", indent, data.debug );
    //dbuffer_printf(buf, "TRANSPARENT %s\n", indent, data.debug );
    buffer_printf(buf, "UNITS %s\n", indent, data.units );

do web

    buf->indent--;
    buffer_printf(buf, "END\n" );
}





