tarexamples:
	echo "I tawt I taw a puddy tat" >| tweety
	echo "Sufferin' succotash" >| sylvester
	chmod ug+x sylvester
	tar cf tweety.tar tweety sylvester
	rm tweety sylvester
	head -c 2048 tweety.tar >| without_zeros.tar
	head -c 1545 tweety.tar >| truncated.tar
	mv tweety.tar without_zeros.tar truncated.tar /tmp
	(cd templates; tar cf tarutils.tar tarutils.c tarutils.h ; mv tarutils.tar /tmp)

