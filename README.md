<div align="center">
<h1>conway's game of life</h1>

samarth kulshrestha

![code quality](https://img.shields.io/codefactor/grade/github/samarthkulshrestha/obfuscate/main?style=for-the-badge)
![top language](https://img.shields.io/github/languages/top/samarthkulshrestha/obfuscate?color=%234877f7&style=for-the-badge)
<br>
![license](https://img.shields.io/github/license/samarthkulshrestha/obfuscate?color=%23f2e85a&style=for-the-badge)
<br/><br/>
</div>

## Introduction

**obfuscate** is a project where the code of a [conway's game of life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) implementation is obfuscated and formatted as a [glider](https://en.wikipedia.org/wiki/Glider_(Conway%27s_Game_of_Life)).

```c
                 x,y,cx,cy,dx,
                 dy,n,f[8][16]
                 ,b[8][16];main
                 (){f[0][1]=1;
                 f[1][2]=1;f[2
                 ][0]=1;f[2][1
                 ]=1;f[2][2]=1

                                 ;for(;;){for(cy
                                 =0;cy<8;++cy){
                                 for(cx=0;cx<16
                                 ;++cx){printf(
                                 "%c",".*"[f[cy
                                 ][cx]]);n=0;for
                                 (dx=-1;dx<=1;++

dx)for(dy=-1;    dy<=1;++dy)if   (!(dx==0&&dy==
0)){x=((cx+dx    )%16+16)%16;y   =((cy+dy)%8+8)
%8;if(f[y][x]    )n+=1;}b[cy][   cx]=f[cy][cx]?
(n==2||n==3):    n==3;}printf(   "\n");}memcpy(
f,b,sizeof(f)    );printf("\033" "[%dA\033[%dD"
,8,16);usleep    (100*1000);}}   //*^7shc*7"jh"
```

## Files
+ [`conway.c`](./conway.c): the obfuscated version formatted as the glider.
+ [`src/conway.obfus.c`](./src/conway.obfus.c): the unformatted obfuscated
  version.
+ [`src/conway.orig.c`](./src/conway.orig.c): the original unobfuscated version.
+ [`src/imgformat.c`](./src/imgfmt.c): the C code formatter.

## Building
running the following commands will build all of the aforementioned files and
put the executables in [`target`](./target).

```console
$ make
$ ./conway
```

## Contribute

+ I <3 pull requests and bug reports!
+ Don't hesitate to [tell me my code-fu sucks](https://github.com/samarthkulshrestha/obfuscate/issues/new), but please tell me why.
+ Feel free to fork the project and try out your own optimisations.

## License

Obfuscate is licensed under the MIT License.

Copyright (c) 2023 Samarth Kulshrestha.
