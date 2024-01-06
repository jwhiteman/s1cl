/* Generated from 2.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.3.0 (rev e31bbee5)
   macosx-unix-clang-x86-64 [ 64bit dload ptables ]
   command line: 2.scm -output-file yo.c
   uses: eval library
*/
#include "chicken.h"

C_externexport  char *  fixedxor(char * t0,char * t1);

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_eval_toplevel)
C_externimport void C_ccall C_eval_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[16];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,21),40,104,101,120,45,108,105,115,116,32,104,101,120,45,115,116,114,105,110,103,41,0,0,0};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,52,32,103,51,54,32,103,51,55,41,0,0,0,0};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,21),40,102,105,120,101,100,45,120,111,114,32,105,110,112,117,116,32,107,101,121,41,0,0,0};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,20),40,102,105,120,101,100,120,111,114,32,105,110,112,117,116,32,107,101,121,41,0,0,0,0};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


C_noret_decl(f_181)
static void C_ccall f_181(C_word c,C_word *av) C_noret;
C_noret_decl(f_184)
static void C_ccall f_184(C_word c,C_word *av) C_noret;
C_noret_decl(f_187)
static void C_ccall f_187(C_word c,C_word *av) C_noret;
C_noret_decl(f_190)
static void C_ccall f_190(C_word c,C_word *av) C_noret;
C_noret_decl(f_192)
static void C_ccall f_192(C_word c,C_word *av) C_noret;
C_noret_decl(f_198)
static void C_ccall f_198(C_word c,C_word *av) C_noret;
C_noret_decl(f_211)
static void C_ccall f_211(C_word c,C_word *av) C_noret;
C_noret_decl(f_215)
static void C_ccall f_215(C_word c,C_word *av) C_noret;
C_noret_decl(f_218)
static void C_ccall f_218(C_word c,C_word *av) C_noret;
C_noret_decl(f_221)
static void C_ccall f_221(C_word c,C_word *av) C_noret;
C_noret_decl(f_232)
static void C_fcall f_232(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_280)
static void C_ccall f_280(C_word c,C_word *av) C_noret;
C_noret_decl(f_284)
static void C_ccall f_284(C_word c,C_word *av) C_noret;
C_noret_decl(f_287)
static void C_ccall f_287(C_word c,C_word *av) C_noret;
C_noret_decl(f_290)
static void C_ccall f_290(C_word c,C_word *av) C_noret;
C_noret_decl(f_300)
static void C_ccall f_300(C_word c,C_word *av) C_noret;
C_noret_decl(f_303)
static void C_ccall f_303(C_word c,C_word *av) C_noret;
C_noret_decl(f_309)
static void C_ccall f_309(C_word c,C_word *av) C_noret;
C_noret_decl(C_toplevel)
C_externexport void C_ccall C_toplevel(C_word c,C_word *av) C_noret;

/* from fixedxor */
 char *  fixedxor(char * t0,char * t1){
C_word x,s=0+2+(t0==NULL?1:C_bytestowords(C_strlen(t0)))+2+(t1==NULL?1:C_bytestowords(C_strlen(t1))),*a=C_alloc(s);
C_callback_adjust_stack(a,s);
x=C_mpointer(&a,(void*)t1);
C_save(x);
x=C_mpointer(&a,(void*)t0);
C_save(x);
return C_string_or_null(C_callback_wrapper((void *)f_280,2));}

C_noret_decl(trf_232)
static void C_ccall trf_232(C_word c,C_word *av) C_noret;
static void C_ccall trf_232(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_232(t0,t1,t2,t3);}

/* k179 */
static void C_ccall f_181(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_181,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_184,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_eval_toplevel(2,av2);}}

/* k182 in k179 */
static void C_ccall f_184(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_184,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_187,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("2.scm:1: chicken.load#load-extension"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[13]);
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[13]+1);
av2[1]=t2;
av2[2]=lf[15];
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
tp(5,av2);}}

/* k185 in k182 in k179 */
static void C_ccall f_187(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_187,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_190,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("2.scm:1: chicken.load#load-extension"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[13]);
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[13]+1);
av2[1]=t2;
av2[2]=lf[14];
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
tp(5,av2);}}

/* k188 in k185 in k182 in k179 */
static void C_ccall f_190(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_190,c,av);}
a=C_alloc(12);
t2=C_mutate((C_word*)lf[0]+1 /* (set! hex-list ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_192,a[2]=((C_word)li0),tmp=(C_word)a,a+=3,tmp));
t3=C_mutate((C_word*)lf[3]+1 /* (set! fixed-xor ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_198,a[2]=((C_word)li2),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[6]+1 /* (set! fixedxor ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_280,a[2]=((C_word)li3),tmp=(C_word)a,a+=3,tmp));
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_303,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("2.scm:22: chicken.platform#return-to-host"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[12]);
C_word *av2=av;
av2[0]=*((C_word*)lf[12]+1);
av2[1]=t5;
tp(2,av2);}}

/* hex-list in k188 in k185 in k182 in k179 */
static void C_ccall f_192(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_192,c,av);}
C_trace(C_text("2.scm:9: regex#string-split-fields"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[1]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[2];
av2[3]=t2;
tp(4,av2);}}

/* fixed-xor in k188 in k185 in k182 in k179 */
static void C_ccall f_198(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_198,c,av);}
a=C_alloc(11);
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_218,a[2]=t6,a[3]=t7,a[4]=t1,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
C_trace(C_text("2.scm:15: hex-list"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[0]);
C_word *av2=av;
av2[0]=*((C_word*)lf[0]+1);
av2[1]=t8;
av2[2]=t2;
tp(3,av2);}}

/* k209 in map-loop24 in k219 in k216 in fixed-xor in k188 in k185 in k182 in k179 */
static void C_ccall f_211(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_211,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_215,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
C_trace(C_text("2.scm:14: scheme#string->number"));
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[7];
av2[3]=C_fix(16);
tp(4,av2);}}

/* k213 in k209 in map-loop24 in k219 in k216 in fixed-xor in k188 in k185 in k182 in k179 */
static void C_ccall f_215(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_215,c,av);}
a=C_alloc(8);
t2=C_s_a_i_bitwise_xor(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,t2,C_SCHEME_END_OF_LIST);
t4=C_i_setslot(((C_word*)((C_word*)t0)[3])[1],C_fix(1),t3);
t5=C_mutate(((C_word *)((C_word*)t0)[3])+1,t3);
t6=((C_word*)((C_word*)t0)[4])[1];
f_232(t6,((C_word*)t0)[5],C_slot(((C_word*)t0)[6],C_fix(1)),C_slot(((C_word*)t0)[7],C_fix(1)));}

/* k216 in fixed-xor in k188 in k185 in k182 in k179 */
static void C_ccall f_218(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_218,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_221,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
C_trace(C_text("2.scm:16: hex-list"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[0]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[0]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
tp(3,av2);}}

/* k219 in k216 in fixed-xor in k188 in k185 in k182 in k179 */
static void C_ccall f_221(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_221,c,av);}
a=C_alloc(8);
t2=C_i_check_list_2(((C_word*)t0)[2],lf[4]);
t3=C_i_check_list_2(t1,lf[4]);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_232,a[2]=((C_word*)t0)[3],a[3]=t5,a[4]=((C_word*)t0)[4],a[5]=((C_word)li1),tmp=(C_word)a,a+=6,tmp));
t7=((C_word*)t5)[1];
f_232(t7,((C_word*)t0)[5],((C_word*)t0)[2],t1);}

/* map-loop24 in k219 in k216 in fixed-xor in k188 in k185 in k182 in k179 */
static void C_fcall f_232(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,3)))){
C_save_and_reclaim_args((void *)trf_232,4,t0,t1,t2,t3);}
a=C_alloc(8);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_211,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,a[6]=t3,a[7]=t7,tmp=(C_word)a,a+=8,tmp);
C_trace(C_text("2.scm:13: scheme#string->number"));
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t8;
av2[2]=t6;
av2[3]=C_fix(16);
tp(4,av2);}}
else{
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* fixedxor in k188 in k185 in k182 in k179 */
static void C_ccall f_280(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_280,c,av);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_284,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
C_trace(C_text("2.scm:18: ##sys#peek-c-string"));
t5=*((C_word*)lf[10]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k282 in fixedxor in k188 in k185 in k182 in k179 */
static void C_ccall f_284(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_284,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_287,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
C_trace(C_text("2.scm:18: ##sys#peek-c-string"));
t3=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k285 in k282 in fixedxor in k188 in k185 in k182 in k179 */
static void C_ccall f_287(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_287,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_290,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_300,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("2.scm:20: fixed-xor"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[3]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[3]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
tp(4,av2);}}

/* k288 in k285 in k282 in fixedxor in k188 in k185 in k182 in k179 */
static void C_ccall f_290(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_290,c,av);}
if(C_truep(t1)){
C_trace(C_text("2.scm:18: ##sys#make-c-string"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[7]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[7]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[6];
tp(4,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k298 in k285 in k282 in fixedxor in k188 in k185 in k182 in k179 */
static void C_ccall f_300(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_300,c,av);}
C_trace(C_text("2.scm:20: format#format"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[8]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[8]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[9];
av2[3]=t1;
tp(4,av2);}}

/* k301 in k188 in k185 in k182 in k179 */
static void C_ccall f_303(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_303,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_309,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("chicken.base#implicit-exit-handler"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[11]);
C_word *av2=av;
av2[0]=*((C_word*)lf[11]+1);
av2[1]=t2;
tp(2,av2);}}

/* k307 in k301 in k188 in k185 in k182 in k179 */
static void C_ccall f_309(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_309,c,av);}
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
if(C_unlikely(!C_demand_2(98))){
C_save(t1);
C_rereclaim2(98*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,16);
lf[0]=C_h_intern(&lf[0],8, C_text("hex-list"));
lf[1]=C_h_intern(&lf[1],25, C_text("regex#string-split-fields"));
lf[2]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002.."));
lf[3]=C_h_intern(&lf[3],9, C_text("fixed-xor"));
lf[4]=C_h_intern(&lf[4],3, C_text("map"));
lf[5]=C_h_intern(&lf[5],21, C_text("scheme#string->number"));
lf[6]=C_h_intern(&lf[6],8, C_text("fixedxor"));
lf[7]=C_h_intern(&lf[7],19, C_text("##sys#make-c-string"));
lf[8]=C_h_intern(&lf[8],13, C_text("format#format"));
lf[9]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006~{~x~}"));
lf[10]=C_h_intern(&lf[10],19, C_text("##sys#peek-c-string"));
lf[11]=C_h_intern(&lf[11],34, C_text("chicken.base#implicit-exit-handler"));
lf[12]=C_h_intern(&lf[12],31, C_text("chicken.platform#return-to-host"));
lf[13]=C_h_intern(&lf[13],27, C_text("chicken.load#load-extension"));
lf[14]=C_h_intern(&lf[14],6, C_text("format"));
lf[15]=C_h_intern(&lf[15],5, C_text("regex"));
C_register_lf2(lf,16,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_181,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[20] = {
{C_text("f_181:_32_2escm"),(void*)f_181},
{C_text("f_184:_32_2escm"),(void*)f_184},
{C_text("f_187:_32_2escm"),(void*)f_187},
{C_text("f_190:_32_2escm"),(void*)f_190},
{C_text("f_192:_32_2escm"),(void*)f_192},
{C_text("f_198:_32_2escm"),(void*)f_198},
{C_text("f_211:_32_2escm"),(void*)f_211},
{C_text("f_215:_32_2escm"),(void*)f_215},
{C_text("f_218:_32_2escm"),(void*)f_218},
{C_text("f_221:_32_2escm"),(void*)f_221},
{C_text("f_232:_32_2escm"),(void*)f_232},
{C_text("f_280:_32_2escm"),(void*)f_280},
{C_text("f_284:_32_2escm"),(void*)f_284},
{C_text("f_287:_32_2escm"),(void*)f_287},
{C_text("f_290:_32_2escm"),(void*)f_290},
{C_text("f_300:_32_2escm"),(void*)f_300},
{C_text("f_303:_32_2escm"),(void*)f_303},
{C_text("f_309:_32_2escm"),(void*)f_309},
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
S|applied compiler syntax:
S|  scheme#map		1
o|eliminated procedure checks: 8 
o|contracted procedure: "(2.scm:12) g3040" 
o|replaced variables: 30 
o|removed binding forms: 17 
o|replaced variables: 3 
o|removed binding forms: 24 
o|removed binding forms: 3 
o|simplifications: ((if . 1) (##core#call . 13)) 
o|  call simplifications:
o|    ##sys#check-list	2
o|    scheme#pair?	2
o|    chicken.bitwise#bitwise-xor
o|    scheme#cons	2
o|    ##sys#setslot
o|    ##sys#slot	5
o|contracted procedure: k200 
o|contracted procedure: k222 
o|contracted procedure: k225 
o|contracted procedure: k273 
o|contracted procedure: k237 
o|contracted procedure: k263 
o|contracted procedure: k267 
o|contracted procedure: k259 
o|contracted procedure: k240 
o|contracted procedure: k243 
o|contracted procedure: k251 
o|contracted procedure: k255 
o|simplifications: ((let . 2)) 
o|removed binding forms: 12 
o|customizable procedures: (map-loop2445) 
o|calls to known targets: 2 
o|fast box initializations: 1 
*/
/* end of file */
