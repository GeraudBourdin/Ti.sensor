/* C++ code produced by gperf version 3.0.3 */
/* Command-line: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/gperf -L C++ -E -t /private/var/folders/0v/slqzg7hs6l74393tj2x_glh80000gn/T/gtwin/sensor-generated/KrollGeneratedBindings.gperf  */
/* Computed positions: -k'' */

#line 3 "/private/var/folders/0v/slqzg7hs6l74393tj2x_glh80000gn/T/gtwin/sensor-generated/KrollGeneratedBindings.gperf"


#include <string.h>
#include <v8.h>
#include <KrollBindings.h>

#include "com.geraudbourdin.sensor.SensorModule.h"


#line 13 "/private/var/folders/0v/slqzg7hs6l74393tj2x_glh80000gn/T/gtwin/sensor-generated/KrollGeneratedBindings.gperf"
struct titanium::bindings::BindEntry;
/* maximum key range = 1, duplicates = 0 */

class SensorBindings
{
private:
  static inline unsigned int hash (const char *str, unsigned int len);
public:
  static struct titanium::bindings::BindEntry *lookupGeneratedInit (const char *str, unsigned int len);
};

inline /*ARGSUSED*/
unsigned int
SensorBindings::hash (register const char *str, register unsigned int len)
{
  return len;
}

struct titanium::bindings::BindEntry *
SensorBindings::lookupGeneratedInit (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 1,
      MIN_WORD_LENGTH = 37,
      MAX_WORD_LENGTH = 37,
      MIN_HASH_VALUE = 37,
      MAX_HASH_VALUE = 37
    };

  static struct titanium::bindings::BindEntry wordlist[] =
    {
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 15 "/private/var/folders/0v/slqzg7hs6l74393tj2x_glh80000gn/T/gtwin/sensor-generated/KrollGeneratedBindings.gperf"
      {"com.geraudbourdin.sensor.SensorModule", ::com::geraudbourdin::sensor::SensorModule::bindProxy, ::com::geraudbourdin::sensor::SensorModule::dispose}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
#line 16 "/private/var/folders/0v/slqzg7hs6l74393tj2x_glh80000gn/T/gtwin/sensor-generated/KrollGeneratedBindings.gperf"

