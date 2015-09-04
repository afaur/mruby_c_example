// #qo LIBS: mruby sqlite3

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <mruby.h>
#include <mruby/compile.h>
#include "mrb_sqlite3.h"

static mrb_value my_c_method(mrb_state *mrb, mrb_value value)
{
  puts("CD Method");
  return value;
}

static mrb_value getstring(mrb_state *mrb, mrb_value value)
{
  char response[100];
  fgets(response, 100, stdin);
  return mrb_str_new_cstr(mrb, response);
}

int main(void)
{
  // Open mrb
  mrb_state *mrb = mrb_open();

  // Setup my_c_method to be used in mruby_code.rb by calling
  // MyModule::my_c_method()
  struct RClass *mymodule = mrb_define_module(mrb, "MyModule");
  mrb_define_class_method(mrb, mymodule, "my_c_method", my_c_method, MRB_ARGS_NONE());
  mrb_define_class_method(mrb, mymodule, "getstring", getstring, MRB_ARGS_NONE());

  // Run sqlite3 gem init so we can use it in mruby_code.rb
  mrb_mruby_sqlite3_gem_init(mrb);

  // Read mruby_code.rb in and run it
  FILE *f = fopen("mruby_code.rb", "r");
  mrb_load_file(mrb, f);

  // Close mrb
  mrb_close(mrb);

  return 0;
}
