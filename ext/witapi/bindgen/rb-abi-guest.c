#include <stdlib.h>
#include <rb-abi-guest.h>

__attribute__((weak, export_name("canonical_abi_realloc")))
void *canonical_abi_realloc(
void *ptr,
size_t orig_size,
size_t org_align,
size_t new_size
) {
  void *ret = realloc(ptr, new_size);
  if (!ret)
  abort();
  return ret;
}

__attribute__((weak, export_name("canonical_abi_free")))
void canonical_abi_free(
void *ptr,
size_t size,
size_t align
) {
  free(ptr);
}

__attribute__((import_module("canonical_abi"), import_name("resource_drop_rb-iseq")))
void __resource_rb_iseq_drop(uint32_t idx);

void rb_abi_guest_rb_iseq_free(rb_abi_guest_rb_iseq_t *ptr) {
  __resource_rb_iseq_drop(ptr->idx);
}

__attribute__((import_module("canonical_abi"), import_name("resource_clone_rb-iseq")))
uint32_t __resource_rb_iseq_clone(uint32_t idx);

rb_abi_guest_rb_iseq_t rb_abi_guest_rb_iseq_clone(rb_abi_guest_rb_iseq_t *ptr) {
  return (rb_abi_guest_rb_iseq_t){__resource_rb_iseq_clone(ptr->idx)};
}

__attribute__((import_module("canonical_abi"), import_name("resource_new_rb-iseq")))
uint32_t __resource_rb_iseq_new(uint32_t val);

rb_abi_guest_rb_iseq_t rb_abi_guest_rb_iseq_new(void *data) {
  return (rb_abi_guest_rb_iseq_t){__resource_rb_iseq_new((uint32_t) data)};
}

__attribute__((import_module("canonical_abi"), import_name("resource_get_rb-iseq")))
uint32_t __resource_rb_iseq_get(uint32_t idx);

void* rb_abi_guest_rb_iseq_get(rb_abi_guest_rb_iseq_t *ptr) {
  return (void*) __resource_rb_iseq_get(ptr->idx);
}

__attribute__((export_name("canonical_abi_drop_rb-iseq")))
void __resource_rb_iseq_dtor(uint32_t val) {
  if (rb_abi_guest_rb_iseq_dtor)
  rb_abi_guest_rb_iseq_dtor((void*) val);
}

__attribute__((import_module("canonical_abi"), import_name("resource_drop_rb-abi-value")))
void __resource_rb_abi_value_drop(uint32_t idx);

void rb_abi_guest_rb_abi_value_free(rb_abi_guest_rb_abi_value_t *ptr) {
  __resource_rb_abi_value_drop(ptr->idx);
}

__attribute__((import_module("canonical_abi"), import_name("resource_clone_rb-abi-value")))
uint32_t __resource_rb_abi_value_clone(uint32_t idx);

rb_abi_guest_rb_abi_value_t rb_abi_guest_rb_abi_value_clone(rb_abi_guest_rb_abi_value_t *ptr) {
  return (rb_abi_guest_rb_abi_value_t){__resource_rb_abi_value_clone(ptr->idx)};
}

__attribute__((import_module("canonical_abi"), import_name("resource_new_rb-abi-value")))
uint32_t __resource_rb_abi_value_new(uint32_t val);

rb_abi_guest_rb_abi_value_t rb_abi_guest_rb_abi_value_new(void *data) {
  return (rb_abi_guest_rb_abi_value_t){__resource_rb_abi_value_new((uint32_t) data)};
}

__attribute__((import_module("canonical_abi"), import_name("resource_get_rb-abi-value")))
uint32_t __resource_rb_abi_value_get(uint32_t idx);

void* rb_abi_guest_rb_abi_value_get(rb_abi_guest_rb_abi_value_t *ptr) {
  return (void*) __resource_rb_abi_value_get(ptr->idx);
}

__attribute__((export_name("canonical_abi_drop_rb-abi-value")))
void __resource_rb_abi_value_dtor(uint32_t val) {
  if (rb_abi_guest_rb_abi_value_dtor)
  rb_abi_guest_rb_abi_value_dtor((void*) val);
}
#include <string.h>

void rb_abi_guest_string_set(rb_abi_guest_string_t *ret, const char *s) {
  ret->ptr = (char*) s;
  ret->len = strlen(s);
}

void rb_abi_guest_string_dup(rb_abi_guest_string_t *ret, const char *s) {
  ret->len = strlen(s);
  ret->ptr = canonical_abi_realloc(NULL, 0, 1, ret->len);
  memcpy(ret->ptr, s, ret->len);
}

void rb_abi_guest_string_free(rb_abi_guest_string_t *ret) {
  canonical_abi_free(ret->ptr, ret->len, 1);
  ret->ptr = NULL;
  ret->len = 0;
}
void rb_abi_guest_list_string_free(rb_abi_guest_list_string_t *ptr) {
  for (size_t i = 0; i < ptr->len; i++) {
    rb_abi_guest_string_free(&ptr->ptr[i]);
  }
  canonical_abi_free(ptr->ptr, ptr->len * 8, 4);
}
typedef struct {
  rb_abi_guest_rb_abi_value_t f0;
  int32_t f1;
} rb_abi_guest_tuple2_rb_abi_value_s32_t;
void rb_abi_guest_list_rb_abi_value_free(rb_abi_guest_list_rb_abi_value_t *ptr) {
  for (size_t i = 0; i < ptr->len; i++) {
    rb_abi_guest_rb_abi_value_free(&ptr->ptr[i]);
  }
  canonical_abi_free(ptr->ptr, ptr->len * 4, 4);
}
static int64_t RET_AREA[2];
__attribute__((export_name("ruby-show-version")))
void __wasm_export_rb_abi_guest_ruby_show_version(void) {
  rb_abi_guest_ruby_show_version();
}
__attribute__((export_name("ruby-init")))
void __wasm_export_rb_abi_guest_ruby_init(void) {
  rb_abi_guest_ruby_init();
}
__attribute__((export_name("ruby-sysinit")))
void __wasm_export_rb_abi_guest_ruby_sysinit(int32_t arg, int32_t arg0) {
  rb_abi_guest_list_string_t arg1 = (rb_abi_guest_list_string_t) { (rb_abi_guest_string_t*)(arg), (size_t)(arg0) };
  rb_abi_guest_ruby_sysinit(&arg1);
}
__attribute__((export_name("ruby-options")))
int32_t __wasm_export_rb_abi_guest_ruby_options(int32_t arg, int32_t arg0) {
  rb_abi_guest_list_string_t arg1 = (rb_abi_guest_list_string_t) { (rb_abi_guest_string_t*)(arg), (size_t)(arg0) };
  rb_abi_guest_rb_iseq_t ret = rb_abi_guest_ruby_options(&arg1);
  return (ret).idx;
}
__attribute__((export_name("ruby-script")))
void __wasm_export_rb_abi_guest_ruby_script(int32_t arg, int32_t arg0) {
  rb_abi_guest_string_t arg1 = (rb_abi_guest_string_t) { (char*)(arg), (size_t)(arg0) };
  rb_abi_guest_ruby_script(&arg1);
}
__attribute__((export_name("ruby-init-loadpath")))
void __wasm_export_rb_abi_guest_ruby_init_loadpath(void) {
  rb_abi_guest_ruby_init_loadpath();
}
__attribute__((export_name("rb-eval-string-protect")))
int32_t __wasm_export_rb_abi_guest_rb_eval_string_protect(int32_t arg, int32_t arg0) {
  rb_abi_guest_string_t arg1 = (rb_abi_guest_string_t) { (char*)(arg), (size_t)(arg0) };
  rb_abi_guest_rb_abi_value_t ret;
  int32_t ret2;
  rb_abi_guest_rb_eval_string_protect(&arg1, &ret, &ret2);
  int32_t ptr = (int32_t) &RET_AREA;
  *((int32_t*)(ptr + 8)) = ((rb_abi_guest_tuple2_rb_abi_value_s32_t){ ret, ret2 }).f1;
  *((int32_t*)(ptr + 0)) = (((rb_abi_guest_tuple2_rb_abi_value_s32_t){ ret, ret2 }).f0).idx;
  return ptr;
}
__attribute__((export_name("rb-funcallv-protect")))
int32_t __wasm_export_rb_abi_guest_rb_funcallv_protect(int32_t arg, int32_t arg0, int32_t arg1, int32_t arg2) {
  rb_abi_guest_list_rb_abi_value_t arg3 = (rb_abi_guest_list_rb_abi_value_t) { (rb_abi_guest_rb_abi_value_t*)(arg1), (size_t)(arg2) };
  rb_abi_guest_rb_abi_value_t ret;
  int32_t ret4;
  rb_abi_guest_rb_funcallv_protect((rb_abi_guest_rb_abi_value_t){ arg }, (uint32_t) (arg0), &arg3, &ret, &ret4);
  int32_t ptr = (int32_t) &RET_AREA;
  *((int32_t*)(ptr + 8)) = ((rb_abi_guest_tuple2_rb_abi_value_s32_t){ ret, ret4 }).f1;
  *((int32_t*)(ptr + 0)) = (((rb_abi_guest_tuple2_rb_abi_value_s32_t){ ret, ret4 }).f0).idx;
  return ptr;
}
__attribute__((export_name("rb-intern")))
int32_t __wasm_export_rb_abi_guest_rb_intern(int32_t arg, int32_t arg0) {
  rb_abi_guest_string_t arg1 = (rb_abi_guest_string_t) { (char*)(arg), (size_t)(arg0) };
  rb_abi_guest_rb_id_t ret = rb_abi_guest_rb_intern(&arg1);
  return (int32_t) (ret);
}
__attribute__((export_name("rb-errinfo")))
int32_t __wasm_export_rb_abi_guest_rb_errinfo(void) {
  rb_abi_guest_rb_abi_value_t ret = rb_abi_guest_rb_errinfo();
  return (ret).idx;
}
__attribute__((export_name("rb-clear-errinfo")))
void __wasm_export_rb_abi_guest_rb_clear_errinfo(void) {
  rb_abi_guest_rb_clear_errinfo();
}
__attribute__((export_name("rstring-ptr")))
int32_t __wasm_export_rb_abi_guest_rstring_ptr(int32_t arg) {
  rb_abi_guest_string_t ret;
  rb_abi_guest_rstring_ptr((rb_abi_guest_rb_abi_value_t){ arg }, &ret);
  int32_t ptr = (int32_t) &RET_AREA;
  *((int32_t*)(ptr + 8)) = (int32_t) (ret).len;
  *((int32_t*)(ptr + 0)) = (int32_t) (ret).ptr;
  return ptr;
}