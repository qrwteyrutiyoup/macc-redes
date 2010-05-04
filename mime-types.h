#ifndef __MYME_TYPES_H__
#define __MYME_TYPES_H__

#include <assert.h>

#define MIMETYPE_COUNT 172

struct mime_type {
	char extension[10];
	char mimetype[32];
} mimetype;

struct mime_type *get_mime_types() 
{
	// auto-generated.. don't edit.

	static struct mime_type *mt = NULL;

	if (mt == NULL) {
		printf("initializing myme types\n");
		mt = (struct mime_type *) malloc(MIMETYPE_COUNT * sizeof(struct mime_type));

		mt[0] = (struct mime_type) {.extension = "ai", .mimetype = "application/postscript"};
		mt[1] = (struct mime_type) {.extension = "aif", .mimetype = "audio/x-aiff"};
		mt[2] = (struct mime_type) {.extension = "aifc", .mimetype = "audio/x-aiff"};
		mt[3] = (struct mime_type) {.extension = "aiff", .mimetype = "audio/x-aiff"};
		mt[4] = (struct mime_type) {.extension = "asc", .mimetype = "text/plain"};
		mt[5] = (struct mime_type) {.extension = "atom", .mimetype = "application/atom+xml"};
		mt[6] = (struct mime_type) {.extension = "au", .mimetype = "audio/basic"};
		mt[7] = (struct mime_type) {.extension = "avi", .mimetype = "video/x-msvideo"};
		mt[8] = (struct mime_type) {.extension = "bcpio", .mimetype = "application/x-bcpio"};
		mt[9] = (struct mime_type) {.extension = "bin", .mimetype = "application/octet-stream"};
		mt[10] = (struct mime_type) {.extension = "bmp", .mimetype = "image/bmp"};
		mt[11] = (struct mime_type) {.extension = "cdf", .mimetype = "application/x-netcdf"};
		mt[12] = (struct mime_type) {.extension = "cgm", .mimetype = "image/cgm"};
		mt[13] = (struct mime_type) {.extension = "class", .mimetype = "application/octet-stream"};
		mt[14] = (struct mime_type) {.extension = "cpio", .mimetype = "application/x-cpio"};
		mt[15] = (struct mime_type) {.extension = "cpt", .mimetype = "application/mac-compactpro"};
		mt[16] = (struct mime_type) {.extension = "csh", .mimetype = "application/x-csh"};
		mt[17] = (struct mime_type) {.extension = "css", .mimetype = "text/css"};
		mt[18] = (struct mime_type) {.extension = "dcr", .mimetype = "application/x-director"};
		mt[19] = (struct mime_type) {.extension = "dif", .mimetype = "video/x-dv"};
		mt[20] = (struct mime_type) {.extension = "dir", .mimetype = "application/x-director"};
		mt[21] = (struct mime_type) {.extension = "djv", .mimetype = "image/vnd.djvu"};
		mt[22] = (struct mime_type) {.extension = "djvu", .mimetype = "image/vnd.djvu"};
		mt[23] = (struct mime_type) {.extension = "dll", .mimetype = "application/octet-stream"};
		mt[24] = (struct mime_type) {.extension = "dmg", .mimetype = "application/octet-stream"};
		mt[25] = (struct mime_type) {.extension = "dms", .mimetype = "application/octet-stream"};
		mt[26] = (struct mime_type) {.extension = "doc", .mimetype = "application/msword"};
		mt[27] = (struct mime_type) {.extension = "dtd", .mimetype = "application/xml-dtd"};
		mt[28] = (struct mime_type) {.extension = "dv", .mimetype = "video/x-dv"};
		mt[29] = (struct mime_type) {.extension = "dvi", .mimetype = "application/x-dvi"};
		mt[30] = (struct mime_type) {.extension = "dxr", .mimetype = "application/x-director"};
		mt[31] = (struct mime_type) {.extension = "eps", .mimetype = "application/postscript"};
		mt[32] = (struct mime_type) {.extension = "etx", .mimetype = "text/x-setext"};
		mt[33] = (struct mime_type) {.extension = "exe", .mimetype = "application/octet-stream"};
		mt[34] = (struct mime_type) {.extension = "ez", .mimetype = "application/andrew-inset"};
		mt[35] = (struct mime_type) {.extension = "gif", .mimetype = "image/gif"};
		mt[36] = (struct mime_type) {.extension = "gram", .mimetype = "application/srgs"};
		mt[37] = (struct mime_type) {.extension = "grxml", .mimetype = "application/srgs+xml"};
		mt[38] = (struct mime_type) {.extension = "gtar", .mimetype = "application/x-gtar"};
		mt[39] = (struct mime_type) {.extension = "hdf", .mimetype = "application/x-hdf"};
		mt[40] = (struct mime_type) {.extension = "hqx", .mimetype = "application/mac-binhex40"};
		mt[41] = (struct mime_type) {.extension = "htm", .mimetype = "text/html"};
		mt[42] = (struct mime_type) {.extension = "html", .mimetype = "text/html"};
		mt[43] = (struct mime_type) {.extension = "ice", .mimetype = "x-conference/x-cooltalk"};
		mt[44] = (struct mime_type) {.extension = "ico", .mimetype = "image/x-icon"};
		mt[45] = (struct mime_type) {.extension = "ics", .mimetype = "text/calendar"};
		mt[46] = (struct mime_type) {.extension = "ief", .mimetype = "image/ief"};
		mt[47] = (struct mime_type) {.extension = "ifb", .mimetype = "text/calendar"};
		mt[48] = (struct mime_type) {.extension = "iges", .mimetype = "model/iges"};
		mt[49] = (struct mime_type) {.extension = "igs", .mimetype = "model/iges"};
		mt[50] = (struct mime_type) {.extension = "jnlp", .mimetype = "application/x-java-jnlp-file"};
		mt[51] = (struct mime_type) {.extension = "jp2", .mimetype = "image/jp2"};
		mt[52] = (struct mime_type) {.extension = "jpe", .mimetype = "image/jpeg"};
		mt[53] = (struct mime_type) {.extension = "jpeg", .mimetype = "image/jpeg"};
		mt[54] = (struct mime_type) {.extension = "jpg", .mimetype = "image/jpeg"};
		mt[55] = (struct mime_type) {.extension = "js", .mimetype = "application/x-javascript"};
		mt[56] = (struct mime_type) {.extension = "kar", .mimetype = "audio/midi"};
		mt[57] = (struct mime_type) {.extension = "latex", .mimetype = "application/x-latex"};
		mt[58] = (struct mime_type) {.extension = "lha", .mimetype = "application/octet-stream"};
		mt[59] = (struct mime_type) {.extension = "lzh", .mimetype = "application/octet-stream"};
		mt[60] = (struct mime_type) {.extension = "m3u", .mimetype = "audio/x-mpegurl"};
		mt[61] = (struct mime_type) {.extension = "m4a", .mimetype = "audio/mp4a-latm"};
		mt[62] = (struct mime_type) {.extension = "m4b", .mimetype = "audio/mp4a-latm"};
		mt[63] = (struct mime_type) {.extension = "m4p", .mimetype = "audio/mp4a-latm"};
		mt[64] = (struct mime_type) {.extension = "m4u", .mimetype = "video/vnd.mpegurl"};
		mt[65] = (struct mime_type) {.extension = "m4v", .mimetype = "video/x-m4v"};
		mt[66] = (struct mime_type) {.extension = "mac", .mimetype = "image/x-macpaint"};
		mt[67] = (struct mime_type) {.extension = "man", .mimetype = "application/x-troff-man"};
		mt[68] = (struct mime_type) {.extension = "mathml", .mimetype = "application/mathml+xml"};
		mt[69] = (struct mime_type) {.extension = "me", .mimetype = "application/x-troff-me"};
		mt[70] = (struct mime_type) {.extension = "mesh", .mimetype = "model/mesh"};
		mt[71] = (struct mime_type) {.extension = "mid", .mimetype = "audio/midi"};
		mt[72] = (struct mime_type) {.extension = "midi", .mimetype = "audio/midi"};
		mt[73] = (struct mime_type) {.extension = "mif", .mimetype = "application/vnd.mif"};
		mt[74] = (struct mime_type) {.extension = "mov", .mimetype = "video/quicktime"};
		mt[75] = (struct mime_type) {.extension = "movie", .mimetype = "video/x-sgi-movie"};
		mt[76] = (struct mime_type) {.extension = "mp2", .mimetype = "audio/mpeg"};
		mt[77] = (struct mime_type) {.extension = "mp3", .mimetype = "audio/mpeg"};
		mt[78] = (struct mime_type) {.extension = "mp4", .mimetype = "video/mp4"};
		mt[79] = (struct mime_type) {.extension = "mpe", .mimetype = "video/mpeg"};
		mt[80] = (struct mime_type) {.extension = "mpeg", .mimetype = "video/mpeg"};
		mt[81] = (struct mime_type) {.extension = "mpg", .mimetype = "video/mpeg"};
		mt[82] = (struct mime_type) {.extension = "mpga", .mimetype = "audio/mpeg"};
		mt[83] = (struct mime_type) {.extension = "ms", .mimetype = "application/x-troff-ms"};
		mt[84] = (struct mime_type) {.extension = "msh", .mimetype = "model/mesh"};
		mt[85] = (struct mime_type) {.extension = "mxu", .mimetype = "video/vnd.mpegurl"};
		mt[86] = (struct mime_type) {.extension = "nc", .mimetype = "application/x-netcdf"};
		mt[87] = (struct mime_type) {.extension = "oda", .mimetype = "application/oda"};
		mt[88] = (struct mime_type) {.extension = "ogg", .mimetype = "application/ogg"};
		mt[89] = (struct mime_type) {.extension = "pbm", .mimetype = "image/x-portable-bitmap"};
		mt[90] = (struct mime_type) {.extension = "pct", .mimetype = "image/pict"};
		mt[91] = (struct mime_type) {.extension = "pdb", .mimetype = "chemical/x-pdb"};
		mt[92] = (struct mime_type) {.extension = "pdf", .mimetype = "application/pdf"};
		mt[93] = (struct mime_type) {.extension = "pgm", .mimetype = "image/x-portable-graymap"};
		mt[94] = (struct mime_type) {.extension = "pgn", .mimetype = "application/x-chess-pgn"};
		mt[95] = (struct mime_type) {.extension = "pic", .mimetype = "image/pict"};
		mt[96] = (struct mime_type) {.extension = "pict", .mimetype = "image/pict"};
		mt[97] = (struct mime_type) {.extension = "png", .mimetype = "image/png"};
		mt[98] = (struct mime_type) {.extension = "pnm", .mimetype = "image/x-portable-anymap"};
		mt[99] = (struct mime_type) {.extension = "pnt", .mimetype = "image/x-macpaint"};
		mt[100] = (struct mime_type) {.extension = "pntg", .mimetype = "image/x-macpaint"};
		mt[101] = (struct mime_type) {.extension = "ppm", .mimetype = "image/x-portable-pixmap"};
		mt[102] = (struct mime_type) {.extension = "ppt", .mimetype = "application/vnd.ms-powerpoint"};
		mt[103] = (struct mime_type) {.extension = "ps", .mimetype = "application/postscript"};
		mt[104] = (struct mime_type) {.extension = "qt", .mimetype = "video/quicktime"};
		mt[105] = (struct mime_type) {.extension = "qti", .mimetype = "image/x-quicktime"};
		mt[106] = (struct mime_type) {.extension = "qtif", .mimetype = "image/x-quicktime"};
		mt[107] = (struct mime_type) {.extension = "ra", .mimetype = "audio/x-pn-realaudio"};
		mt[108] = (struct mime_type) {.extension = "ram", .mimetype = "audio/x-pn-realaudio"};
		mt[109] = (struct mime_type) {.extension = "ras", .mimetype = "image/x-cmu-raster"};
		mt[110] = (struct mime_type) {.extension = "rdf", .mimetype = "application/rdf+xml"};
		mt[111] = (struct mime_type) {.extension = "rgb", .mimetype = "image/x-rgb"};
		mt[112] = (struct mime_type) {.extension = "rm", .mimetype = "application/vnd.rn-realmedia"};
		mt[113] = (struct mime_type) {.extension = "roff", .mimetype = "application/x-troff"};
		mt[114] = (struct mime_type) {.extension = "rtf", .mimetype = "text/rtf"};
		mt[115] = (struct mime_type) {.extension = "rtx", .mimetype = "text/richtext"};
		mt[116] = (struct mime_type) {.extension = "sgm", .mimetype = "text/sgml"};
		mt[117] = (struct mime_type) {.extension = "sgml", .mimetype = "text/sgml"};
		mt[118] = (struct mime_type) {.extension = "sh", .mimetype = "application/x-sh"};
		mt[119] = (struct mime_type) {.extension = "shar", .mimetype = "application/x-shar"};
		mt[120] = (struct mime_type) {.extension = "silo", .mimetype = "model/mesh"};
		mt[121] = (struct mime_type) {.extension = "sit", .mimetype = "application/x-stuffit"};
		mt[122] = (struct mime_type) {.extension = "skd", .mimetype = "application/x-koan"};
		mt[123] = (struct mime_type) {.extension = "skm", .mimetype = "application/x-koan"};
		mt[124] = (struct mime_type) {.extension = "skp", .mimetype = "application/x-koan"};
		mt[125] = (struct mime_type) {.extension = "skt", .mimetype = "application/x-koan"};
		mt[126] = (struct mime_type) {.extension = "smi", .mimetype = "application/smil"};
		mt[127] = (struct mime_type) {.extension = "smil", .mimetype = "application/smil"};
		mt[128] = (struct mime_type) {.extension = "snd", .mimetype = "audio/basic"};
		mt[129] = (struct mime_type) {.extension = "so", .mimetype = "application/octet-stream"};
		mt[130] = (struct mime_type) {.extension = "spl", .mimetype = "application/x-futuresplash"};
		mt[131] = (struct mime_type) {.extension = "src", .mimetype = "application/x-wais-source"};
		mt[132] = (struct mime_type) {.extension = "sv4cpio", .mimetype = "application/x-sv4cpio"};
		mt[133] = (struct mime_type) {.extension = "sv4crc", .mimetype = "application/x-sv4crc"};
		mt[134] = (struct mime_type) {.extension = "svg", .mimetype = "image/svg+xml"};
		mt[135] = (struct mime_type) {.extension = "swf", .mimetype = "application/x-shockwave-flash"};
		mt[136] = (struct mime_type) {.extension = "t", .mimetype = "application/x-troff"};
		mt[137] = (struct mime_type) {.extension = "tar", .mimetype = "application/x-tar"};
		mt[138] = (struct mime_type) {.extension = "tcl", .mimetype = "application/x-tcl"};
		mt[139] = (struct mime_type) {.extension = "tex", .mimetype = "application/x-tex"};
		mt[140] = (struct mime_type) {.extension = "texi", .mimetype = "application/x-texinfo"};
		mt[141] = (struct mime_type) {.extension = "texinfo", .mimetype = "application/x-texinfo"};
		mt[142] = (struct mime_type) {.extension = "tif", .mimetype = "image/tiff"};
		mt[143] = (struct mime_type) {.extension = "tiff", .mimetype = "image/tiff"};
		mt[144] = (struct mime_type) {.extension = "tr", .mimetype = "application/x-troff"};
		mt[145] = (struct mime_type) {.extension = "tsv", .mimetype = "text/tab-separated-values"};
		mt[146] = (struct mime_type) {.extension = "txt", .mimetype = "text/plain"};
		mt[147] = (struct mime_type) {.extension = "ustar", .mimetype = "application/x-ustar"};
		mt[148] = (struct mime_type) {.extension = "vcd", .mimetype = "application/x-cdlink"};
		mt[149] = (struct mime_type) {.extension = "vrml", .mimetype = "model/vrml"};
		mt[150] = (struct mime_type) {.extension = "vxml", .mimetype = "application/voicexml+xml"};
		mt[151] = (struct mime_type) {.extension = "wav", .mimetype = "audio/x-wav"};
		mt[152] = (struct mime_type) {.extension = "wbmp", .mimetype = "image/vnd.wap.wbmp"};
		mt[153] = (struct mime_type) {.extension = "wbmxl", .mimetype = "application/vnd.wap.wbxml"};
		mt[154] = (struct mime_type) {.extension = "wml", .mimetype = "text/vnd.wap.wml"};
		mt[155] = (struct mime_type) {.extension = "wmlc", .mimetype = "application/vnd.wap.wmlc"};
		mt[156] = (struct mime_type) {.extension = "wmls", .mimetype = "text/vnd.wap.wmlscript"};
		mt[157] = (struct mime_type) {.extension = "wmlsc", .mimetype = "application/vnd.wap.wmlscriptc"};
		mt[158] = (struct mime_type) {.extension = "wrl", .mimetype = "model/vrml"};
		mt[159] = (struct mime_type) {.extension = "xbm", .mimetype = "image/x-xbitmap"};
		mt[160] = (struct mime_type) {.extension = "xht", .mimetype = "application/xhtml+xml"};
		mt[161] = (struct mime_type) {.extension = "xhtml", .mimetype = "application/xhtml+xml"};
		mt[162] = (struct mime_type) {.extension = "xls", .mimetype = "application/vnd.ms-excel"};
		mt[163] = (struct mime_type) {.extension = "xml", .mimetype = "application/xml"};
		mt[164] = (struct mime_type) {.extension = "xpm", .mimetype = "image/x-xpixmap"};
		mt[165] = (struct mime_type) {.extension = "xsl", .mimetype = "application/xml"};
		mt[166] = (struct mime_type) {.extension = "xslt", .mimetype = "application/xslt+xml"};
		mt[167] = (struct mime_type) {.extension = "xul", .mimetype = "application/vnd.mozilla.xul+xml"};
		mt[168] = (struct mime_type) {.extension = "xwd", .mimetype = "image/x-xwindowdump"};
		mt[169] = (struct mime_type) {.extension = "xyz", .mimetype = "chemical/x-xyz"};
		mt[170] = (struct mime_type) {.extension = "zip", .mimetype = "application/zip"};
		mt[171] = (struct mime_type) {.extension = "com", .mimetype = "application/octet-stream"};
	}

	assert(mt);
	return mt;
}

#endif

