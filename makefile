all: conway.orig conway.obfus imgfmt conway

conway.orig: src/conway.orig.c
	cc -o target/conway.orig src/conway.orig.c

conway.obfus: src/conway.obfus.c
	cc -w -o target/conway.obfus src/conway.obfus.c

imgfmt: src/imgfmt.c
	cc -Wall -Wextra -o target/imgfmt src/imgfmt.c -lm

conway: conway.c
	cc -w conway conway.c
