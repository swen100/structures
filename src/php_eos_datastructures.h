/*
  +----------------------------------------------------------------------+
  | For PHP Version 8                                                    |
  +----------------------------------------------------------------------+
  | Copyright (c) 2015-2017 Elizabeth M Smith                            |
  +----------------------------------------------------------------------+
  | http://www.opensource.org/licenses/mit-license.php  MIT License      |
  | Also available in LICENSE                                            |
  +----------------------------------------------------------------------+
  | Author: Elizabeth M Smith <auroraeosrose@gmail.com>                  |
  +----------------------------------------------------------------------+
*/

#ifndef PHP_EOS_DATASTRUCTURES_EXT_H
#define PHP_EOS_DATASTRUCTURES_EXT_H

#include <php.h>

extern zend_module_entry eos_datastructures_module_entry;
#define phpext_eos_datastructures_ptr &eos_datastructures_module_entry

#define PHP_EOS_DATASTRUCTURES_VERSION "1.0.0-dev"
#define EOS_DATASTRUCTURES_NAMESPACE "Eos\\DataStructures"

#ifdef PHP_WIN32
#   define PHP_EOS_DATASTRUCTURES_API __declspec(dllexport)
#elif defined(__GNUCC__) && __GNUC__ >= 4
#   define PHP_EOS_DATASTRUCTURES_API extern __attribute__ ((visibility("default")))
#else
#   define PHP_EOS_DATASTRUCTURES_API extern
#endif

#ifndef convert_to_explicit_type
#define convert_to_explicit_type(pzv, type)		\
	do {										\
		switch (type) {							\
			case IS_NULL:						\
				convert_to_null(pzv);			\
				break;							\
			case IS_LONG:						\
				convert_to_long(pzv);			\
				break;							\
			case IS_DOUBLE:						\
				convert_to_double(pzv);			\
				break;							\
			case _IS_BOOL:						\
				convert_to_boolean(pzv);		\
				break;							\
			case IS_ARRAY:						\
				convert_to_array(pzv);			\
				break;							\
			case IS_OBJECT:						\
				convert_to_object(pzv);			\
				break;							\
			case IS_STRING:						\
				convert_to_string(pzv);			\
				break;							\
			default:							\
				assert(0);						\
				break;							\
		}										\
	} while (0);
#endif

#endif /* PHP_EOS_DATASTRUCTURES_EXT_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
