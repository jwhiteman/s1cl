/* Generated from 2.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.3.0 (rev e31bbee5)
   macosx-unix-clang-x86-64 [ 64bit dload ptables ]
   command line: 2.scm -output-file output.c
   uses: eval library
*/
#include "chicken.h"

#include "2.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_eval_toplevel)
C_externimport void C_ccall C_eval_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[11];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,17),40,102,114,101,101,32,99,45,115,116,114,105,110,103,49,52,41,0,0,0,0,0,0,0};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,33),40,102,105,120,101,100,45,120,111,114,32,99,45,115,116,114,105,110,103,50,49,32,99,45,115,116,114,105,110,103,50,50,41,0,0,0,0,0,0,0};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


/* from k177 in k173 in fixed-xor in k148 in k145 in k142 */
C_regparm static C_word C_fcall stub23(C_word C_buf,C_word C_a0,C_word C_a1){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
char * t0=(char * )C_string_or_null(C_a0);
char * t1=(char * )C_string_or_null(C_a1);
C_r=C_mpointer(&C_a,(void*)fixed_xor(t0,t1));
return C_r;}

/* from k155 in free in k148 in k145 in k142 */
C_regparm static C_word C_fcall stub15(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
char * t0=(char * )C_string_or_null(C_a0);
free(t0);
return C_r;}

C_noret_decl(f_144)
static void C_ccall f_144(C_word c,C_word *av) C_noret;
C_noret_decl(f_147)
static void C_ccall f_147(C_word c,C_word *av) C_noret;
C_noret_decl(f_150)
static void C_ccall f_150(C_word c,C_word *av) C_noret;
C_noret_decl(f_152)
static void C_ccall f_152(C_word c,C_word *av) C_noret;
C_noret_decl(f_157)
static void C_ccall f_157(C_word c,C_word *av) C_noret;
C_noret_decl(f_166)
static void C_ccall f_166(C_word c,C_word *av) C_noret;
C_noret_decl(f_175)
static void C_ccall f_175(C_word c,C_word *av) C_noret;
C_noret_decl(f_179)
static void C_ccall f_179(C_word c,C_word *av) C_noret;
C_noret_decl(f_196)
static void C_ccall f_196(C_word c,C_word *av) C_noret;
C_noret_decl(f_199)
static void C_ccall f_199(C_word c,C_word *av) C_noret;
C_noret_decl(f_205)
static void C_ccall f_205(C_word c,C_word *av) C_noret;
C_noret_decl(C_toplevel)
C_externexport void C_ccall C_toplevel(C_word c,C_word *av) C_noret;

/* k142 */
static void C_ccall f_144(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_144,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_147,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_eval_toplevel(2,av2);}}

/* k145 in k142 */
static void C_ccall f_147(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_147,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_150,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("2.scm:1: chicken.load#load-extension"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[9]);
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t2;
av2[2]=lf[10];
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
tp(5,av2);}}

/* k148 in k145 in k142 */
static void C_ccall f_150(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_150,c,av);}
a=C_alloc(9);
t2=C_mutate((C_word*)lf[0]+1 /* (set! free ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_152,a[2]=((C_word)li0),tmp=(C_word)a,a+=3,tmp));
t3=C_mutate((C_word*)lf[2]+1 /* (set! fixed-xor ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_166,a[2]=((C_word)li1),tmp=(C_word)a,a+=3,tmp));
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_196,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("2.scm:14: fixed-xor"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[2]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[2]+1);
av2[1]=t4;
av2[2]=lf[7];
av2[3]=lf[8];
tp(4,av2);}}

/* free in k148 in k145 in k142 */
static void C_ccall f_152(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_152,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_157,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
if(C_truep(t2)){
C_trace(C_text("2.scm:5: ##sys#make-c-string"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[1]);
C_word *av2=av;
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t3;
av2[2]=C_i_foreign_string_argumentp(t2);
tp(3,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
f_157(2,av2);}}}

/* k155 in free in k148 in k145 in k142 */
static void C_ccall f_157(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_157,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=stub15(C_SCHEME_UNDEFINED,t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* fixed-xor in k148 in k145 in k142 */
static void C_ccall f_166(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_166,c,av);}
a=C_alloc(10);
t4=C_a_i_bytevector(&a,1,C_fix(3));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_175,a[2]=t1,a[3]=t4,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
if(C_truep(t2)){
C_trace(C_text("2.scm:8: ##sys#make-c-string"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[1]);
C_word *av2=av;
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t5;
av2[2]=C_i_foreign_string_argumentp(t2);
tp(3,av2);}}
else{
t6=t5;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_FALSE;
f_175(2,av2);}}}

/* k173 in fixed-xor in k148 in k145 in k142 */
static void C_ccall f_175(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_175,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_179,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
if(C_truep(((C_word*)t0)[4])){
C_trace(C_text("2.scm:8: ##sys#make-c-string"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[1]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t2;
av2[2]=C_i_foreign_string_argumentp(((C_word*)t0)[4]);
tp(3,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_179(2,av2);}}}

/* k177 in k173 in fixed-xor in k148 in k145 in k142 */
static void C_ccall f_179(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_179,c,av);}
C_trace(C_text("2.scm:8: ##sys#peek-c-string"));
t2=*((C_word*)lf[3]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=stub23(((C_word*)t0)[3],((C_word*)t0)[4],t1);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k194 in k148 in k145 in k142 */
static void C_ccall f_196(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_196,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_199,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("2.scm:16: format#format"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[5]);
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t2;
av2[2]=C_SCHEME_TRUE;
av2[3]=lf[6];
av2[4]=t1;
tp(5,av2);}}

/* k197 in k194 in k148 in k145 in k142 */
static void C_ccall f_199(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_199,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_205,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("chicken.base#implicit-exit-handler"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[4]);
C_word *av2=av;
av2[0]=*((C_word*)lf[4]+1);
av2[1]=t2;
tp(2,av2);}}

/* k203 in k197 in k194 in k148 in k145 in k142 */
static void C_ccall f_205(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_205,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)C_fast_retrieve_proc(t2))(2,av2);}}

/* toplevel */
static C_TLS int toplevel_initialized=0;
C_main_entry_point

void C_ccall C_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("toplevel"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(56))){
C_save(t1);
C_rereclaim2(56*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,11);
lf[0]=C_h_intern(&lf[0],4, C_text("free"));
lf[1]=C_h_intern(&lf[1],19, C_text("##sys#make-c-string"));
lf[2]=C_h_intern(&lf[2],9, C_text("fixed-xor"));
lf[3]=C_h_intern(&lf[3],19, C_text("##sys#peek-c-string"));
lf[4]=C_h_intern(&lf[4],34, C_text("chicken.base#implicit-exit-handler"));
lf[5]=C_h_intern(&lf[5],13, C_text("format#format"));
lf[6]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022The result is ~a~%"));
lf[7]=C_decode_literal(C_heaptop,C_text("\376B\000\000$1c0111001f010100061a024b53535009181c"));
lf[8]=C_decode_literal(C_heaptop,C_text("\376B\000\000$686974207468652062756c6c277320657965"));
lf[9]=C_h_intern(&lf[9],27, C_text("chicken.load#load-extension"));
lf[10]=C_h_intern(&lf[10],6, C_text("format"));
C_register_lf2(lf,11,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_144,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[13] = {
{C_text("f_144:_32_2escm"),(void*)f_144},
{C_text("f_147:_32_2escm"),(void*)f_147},
{C_text("f_150:_32_2escm"),(void*)f_150},
{C_text("f_152:_32_2escm"),(void*)f_152},
{C_text("f_157:_32_2escm"),(void*)f_157},
{C_text("f_166:_32_2escm"),(void*)f_166},
{C_text("f_175:_32_2escm"),(void*)f_175},
{C_text("f_179:_32_2escm"),(void*)f_179},
{C_text("f_196:_32_2escm"),(void*)f_196},
{C_text("f_199:_32_2escm"),(void*)f_199},
{C_text("f_205:_32_2escm"),(void*)f_205},
{C_text("toplevel:_32_2escm"),(void*)C_toplevel},
{NULL,NULL}};
#endif

static C_PTABLE_ENTRY *create_ptable(void){
#ifdef C_ENABLE_PTABLES
return ptable;
#else
return NULL;
#endif
}

/*
o|eliminated procedure checks: 4 
o|replaced variables: 18 
o|removed binding forms: 6 
o|removed binding forms: 15 
o|simplifications: ((let . 1) (##core#call . 3)) 
o|  call simplifications:
o|    ##sys#foreign-string-argument	3
o|contracted procedure: k162 
o|contracted procedure: k184 
o|contracted procedure: k191 
o|simplifications: ((let . 3)) 
o|removed binding forms: 3 
o|calls to known targets: 3 
*/
/* end of file */
