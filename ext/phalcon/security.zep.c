
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 * Phalcon\Security
 *
 * This component provides a set of functions to improve the security in Phalcon applications
 *
 *<code>
 * $login    = $this->request->getPost("login");
 * $password = $this->request->getPost("password");
 *
 * $user = Users::findFirstByLogin($login);
 *
 * if ($user) {
 *     if ($this->security->checkHash($password, $user->password)) {
 *         // The password is valid
 *     }
 * }
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Security) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Security, phalcon, security, phalcon_security_method_entry, 0);

	zend_declare_property_null(phalcon_security_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_security_ce, SL("_workFactor"), 8, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_security_ce, SL("_numberBytes"), 16, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_security_ce, SL("_tokenKeySessionID"), "$PHALCON/CSRF/KEY$", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_security_ce, SL("_tokenValueSessionID"), "$PHALCON/CSRF$", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_security_ce, SL("_token"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_security_ce, SL("_tokenKey"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_security_ce, SL("_random"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_security_ce, SL("_defaultHash"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_DEFAULT"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_STD_DES"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_EXT_DES"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_MD5"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_BLOWFISH"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_BLOWFISH_A"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_BLOWFISH_X"), 6 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_BLOWFISH_Y"), 7 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_SHA256"), 8 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_security_ce, SL("CRYPT_SHA512"), 9 TSRMLS_CC);

	zend_class_implements(phalcon_security_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Security, setWorkFactor) {

	zval *workFactor;

	zephir_fetch_params(0, 1, 0, &workFactor);



	zephir_update_property_this(getThis(), SL("_workFactor"), workFactor TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Phalcon_Security, getWorkFactor) {

	

	RETURN_MEMBER(getThis(), "_workFactor");

}

/**
 * Phalcon\Security constructor
 */
PHP_METHOD(Phalcon_Security, __construct) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalcon_security_random_ce);
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_this(getThis(), SL("_random"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Security, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Security, getDI) {

	

	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Sets a number of bytes to be generated by the openssl pseudo random generator
 */
PHP_METHOD(Phalcon_Security, setRandomBytes) {

	zval *randomBytes_param = NULL, *_0;
	long randomBytes;

	zephir_fetch_params(0, 1, 0, &randomBytes_param);

	if (UNEXPECTED(Z_TYPE_P(randomBytes_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'randomBytes' must be a long") TSRMLS_CC);
		RETURN_NULL();
	}
	randomBytes = Z_LVAL_P(randomBytes_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, randomBytes);
	zephir_update_property_this(getThis(), SL("_numberBytes"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns a number of bytes to be generated by the openssl pseudo random generator
 */
PHP_METHOD(Phalcon_Security, getRandomBytes) {

	

	RETURN_MEMBER(getThis(), "_numberBytes");

}

/**
 * Returns a secure random number generator instance
 */
PHP_METHOD(Phalcon_Security, getRandom) {

	

	RETURN_MEMBER(getThis(), "_random");

}

/**
 * Generate a >22-length pseudo random string to be used as salt for passwords
 */
PHP_METHOD(Phalcon_Security, getSaltBytes) {

	zend_bool _3$$4;
	zval *numberBytes_param = NULL, *safeBytes = NULL, *_0$$3, *_1$$4, *_2$$4 = NULL;
	zend_long numberBytes, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &numberBytes_param);

	if (!numberBytes_param) {
		numberBytes = 0;
	} else {
		numberBytes = zephir_get_intval(numberBytes_param);
	}


	if (!(numberBytes)) {
		ZEPHIR_OBS_VAR(_0$$3);
		zephir_read_property_this(&_0$$3, this_ptr, SL("_numberBytes"), PH_NOISY_CC);
		numberBytes = zephir_get_intval(_0$$3);
	}
	while (1) {
		_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_random"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_2$$4);
		ZVAL_LONG(_2$$4, numberBytes);
		ZEPHIR_CALL_METHOD(&safeBytes, _1$$4, "base64safe", NULL, 0, _2$$4);
		zephir_check_call_status();
		_3$$4 = !zephir_is_true(safeBytes);
		if (!(_3$$4)) {
			_3$$4 = zephir_fast_strlen_ev(safeBytes) < numberBytes;
		}
		if (_3$$4) {
			continue;
		}
		break;
	}
	RETURN_CCTOR(safeBytes);

}

/**
 * Creates a password hash using bcrypt with a pseudo random salt
 */
PHP_METHOD(Phalcon_Security, hash) {

	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	zend_long workFactor, ZEPHIR_LAST_CALL_STATUS, hash = 0;
	zval *password_param = NULL, *workFactor_param = NULL, *saltBytes = NULL, *_1, *_0$$3, *_2$$12 = NULL, *_3$$12, *_5$$13, *_7$$15 = NULL, *_8$$15, *_9$$17, _10$$17, _11$$17, *_12$$17 = NULL, *_13$$17;
	zval *password = NULL, *variant = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &password_param, &workFactor_param);

	zephir_get_strval(password, password_param);
	if (!workFactor_param) {
		workFactor = 0;
	} else {
		workFactor = zephir_get_intval(workFactor_param);
	}


	if (!(workFactor)) {
		ZEPHIR_OBS_VAR(_0$$3);
		zephir_read_property_this(&_0$$3, this_ptr, SL("_workFactor"), PH_NOISY_CC);
		workFactor = zephir_get_intval(_0$$3);
	}
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_defaultHash"), PH_NOISY_CC);
	hash = zephir_get_intval(_1);
	do {
		if (hash == 5) {
			ZEPHIR_INIT_VAR(variant);
			ZVAL_STRING(variant, "a", 1);
			break;
		}
		if (hash == 6) {
			ZEPHIR_INIT_NVAR(variant);
			ZVAL_STRING(variant, "x", 1);
			break;
		}
		if (hash == 7) {
			ZEPHIR_INIT_NVAR(variant);
			ZVAL_STRING(variant, "y", 1);
			break;
		}
		if (hash == 3) {
			ZEPHIR_INIT_NVAR(variant);
			ZVAL_STRING(variant, "1", 1);
			break;
		}
		if (hash == 8) {
			ZEPHIR_INIT_NVAR(variant);
			ZVAL_STRING(variant, "5", 1);
			break;
		}
		if (hash == 9) {
			ZEPHIR_INIT_NVAR(variant);
			ZVAL_STRING(variant, "6", 1);
			break;
		}
		ZEPHIR_INIT_NVAR(variant);
		ZVAL_STRING(variant, "y", 1);
		break;
	} while(0);

	do {
		if (hash == 1 || hash == 2) {
			if (hash == 2) {
				ZEPHIR_INIT_VAR(_3$$12);
				ZVAL_LONG(_3$$12, 8);
				ZEPHIR_CALL_METHOD(&_2$$12, this_ptr, "getsaltbytes", &_4, 0, _3$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(saltBytes);
				ZEPHIR_CONCAT_SV(saltBytes, "_", _2$$12);
			} else {
				ZEPHIR_INIT_VAR(_5$$13);
				ZVAL_LONG(_5$$13, 2);
				ZEPHIR_CALL_METHOD(&saltBytes, this_ptr, "getsaltbytes", &_4, 0, _5$$13);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(saltBytes) != IS_STRING) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_exception_ce, "Unable to get random bytes for the salt", "phalcon/security.zep", 222);
				return;
			}
			ZEPHIR_RETURN_CALL_FUNCTION("crypt", &_6, 435, password, saltBytes);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (hash == 3 || hash == 8 || hash == 9) {
			ZEPHIR_INIT_VAR(_7$$15);
			if (hash == 3) {
				ZEPHIR_INIT_NVAR(_7$$15);
				ZVAL_LONG(_7$$15, 12);
			} else {
				ZEPHIR_INIT_NVAR(_7$$15);
				ZVAL_LONG(_7$$15, 16);
			}
			ZEPHIR_CALL_METHOD(&saltBytes, this_ptr, "getsaltbytes", &_4, 0, _7$$15);
			zephir_check_call_status();
			if (Z_TYPE_P(saltBytes) != IS_STRING) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_exception_ce, "Unable to get random bytes for the salt", "phalcon/security.zep", 239);
				return;
			}
			ZEPHIR_INIT_VAR(_8$$15);
			ZEPHIR_CONCAT_SVSVS(_8$$15, "$", variant, "$", saltBytes, "$");
			ZEPHIR_RETURN_CALL_FUNCTION("crypt", &_6, 435, password, _8$$15);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(_9$$17);
		ZVAL_LONG(_9$$17, 22);
		ZEPHIR_CALL_METHOD(&saltBytes, this_ptr, "getsaltbytes", &_4, 0, _9$$17);
		zephir_check_call_status();
		if (Z_TYPE_P(saltBytes) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_exception_ce, "Unable to get random bytes for the salt", "phalcon/security.zep", 262);
			return;
		}
		if (workFactor < 4) {
			workFactor = 4;
		} else {
			if (workFactor > 31) {
				workFactor = 31;
			}
		}
		ZEPHIR_SINIT_VAR(_10$$17);
		ZVAL_STRING(&_10$$17, "%02s", 0);
		ZEPHIR_SINIT_VAR(_11$$17);
		ZVAL_LONG(&_11$$17, workFactor);
		ZEPHIR_CALL_FUNCTION(&_12$$17, "sprintf", NULL, 204, &_10$$17, &_11$$17);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_13$$17);
		ZEPHIR_CONCAT_SVSVSVS(_13$$17, "$2", variant, "$", _12$$17, "$", saltBytes, "$");
		ZEPHIR_RETURN_CALL_FUNCTION("crypt", &_6, 435, password, _13$$17);
		zephir_check_call_status();
		RETURN_MM();
	} while(0);

	RETURN_MM_STRING("", 1);

}

/**
 * Checks a plain text password and its hash version to check if the password matches
 */
PHP_METHOD(Phalcon_Security, checkHash) {

	unsigned char _4$$5;
	zend_bool _0$$3;
	long _3;
	char ch = 0;
	zend_long maxPassLength, ZEPHIR_LAST_CALL_STATUS, i = 0, sum = 0, cryptedLength = 0, passwordLength = 0;
	zval *password_param = NULL, *passwordHash_param = NULL, *maxPassLength_param = NULL, *_1 = NULL;
	zval *password = NULL, *passwordHash = NULL, *cryptedHash = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &password_param, &passwordHash_param, &maxPassLength_param);

	zephir_get_strval(password, password_param);
	zephir_get_strval(passwordHash, passwordHash_param);
	if (!maxPassLength_param) {
		maxPassLength = 0;
	} else {
		maxPassLength = zephir_get_intval(maxPassLength_param);
	}


	if (maxPassLength) {
		_0$$3 = maxPassLength > 0;
		if (_0$$3) {
			_0$$3 = zephir_fast_strlen_ev(password) > maxPassLength;
		}
		if (_0$$3) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_FUNCTION(&_1, "crypt", NULL, 435, password, passwordHash);
	zephir_check_call_status();
	zephir_get_strval(_2, _1);
	ZEPHIR_CPY_WRT(cryptedHash, _2);
	cryptedLength = zephir_fast_strlen_ev(cryptedHash);
	passwordLength = zephir_fast_strlen_ev(passwordHash);
	zephir_concat_self(&cryptedHash, passwordHash TSRMLS_CC);
	sum = (cryptedLength - passwordLength);
	for (_3 = 0; _3 < Z_STRLEN_P(passwordHash); _3++) {
		i = _3; 
		ch = ZEPHIR_STRING_OFFSET(passwordHash, _3);
		_4$$5 = ZEPHIR_STRING_OFFSET(cryptedHash, i);
		sum = (sum | ((_4$$5 ^ ch)));
	}
	RETURN_MM_BOOL(0 == sum);

}

/**
 * Checks if a password hash is a valid bcrypt's hash
 */
PHP_METHOD(Phalcon_Security, isLegacyHash) {

	zval *passwordHash_param = NULL;
	zval *passwordHash = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &passwordHash_param);

	zephir_get_strval(passwordHash, passwordHash_param);


	RETURN_MM_BOOL(zephir_start_with_str(passwordHash, SL("$2a$")));

}

/**
 * Generates a pseudo random token key to be used as input's name in a CSRF check
 */
PHP_METHOD(Phalcon_Security, getTokenKey) {

	zval *dependencyInjector = NULL, *session = NULL, *_0, *_1$$3, *_2$$3 = NULL, *_3$$3, *_4$$3 = NULL, *_5$$3, *_6$$3, *_7$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_tokenKey"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(dependencyInjector, _1$$3);
		if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_exception_ce, "A dependency injection container is required to access the 'session' service", "phalcon/security.zep", 327);
			return;
		}
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_random"), PH_NOISY_CC);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_numberBytes"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_2$$3, _1$$3, "base64safe", NULL, 0, _3$$3);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("_tokenKey"), _2$$3 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_5$$3);
		ZVAL_STRING(_5$$3, "session", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_4$$3, dependencyInjector, "getshared", NULL, 0, _5$$3);
		zephir_check_temp_parameter(_5$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(session, _4$$3);
		_6$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_tokenKeySessionID"), PH_NOISY_CC);
		_7$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_tokenKey"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, session, "set", NULL, 0, _6$$3, _7$$3);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "_tokenKey");

}

/**
 * Generates a pseudo random token value to be used as input's value in a CSRF check
 */
PHP_METHOD(Phalcon_Security, getToken) {

	zval *dependencyInjector = NULL, *session = NULL, *_0, *_1$$3, *_2$$3 = NULL, *_3$$3, *_4$$3, *_5$$3 = NULL, *_6$$3, *_7$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_random"), PH_NOISY_CC);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_numberBytes"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_2$$3, _1$$3, "base64safe", NULL, 0, _3$$3);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("_token"), _2$$3 TSRMLS_CC);
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(dependencyInjector, _4$$3);
		if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_exception_ce, "A dependency injection container is required to access the 'session' service", "phalcon/security.zep", 351);
			return;
		}
		ZEPHIR_INIT_VAR(_6$$3);
		ZVAL_STRING(_6$$3, "session", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_5$$3, dependencyInjector, "getshared", NULL, 0, _6$$3);
		zephir_check_temp_parameter(_6$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(session, _5$$3);
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_tokenValueSessionID"), PH_NOISY_CC);
		_7$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, session, "set", NULL, 0, _4$$3, _7$$3);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "_token");

}

/**
 * Check if the CSRF token sent in the request is the same that the current in session
 */
PHP_METHOD(Phalcon_Security, checkToken) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool destroyIfValid, _5;
	zval *tokenKey = NULL, *tokenValue = NULL, *destroyIfValid_param = NULL, *dependencyInjector = NULL, *session = NULL, *request = NULL, *equals = NULL, *userToken = NULL, *knownToken = NULL, *_0, *_1 = NULL, *_2, *_3$$4, *_4$$6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &tokenKey, &tokenValue, &destroyIfValid_param);

	if (!tokenKey) {
		ZEPHIR_CPY_WRT(tokenKey, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(tokenKey);
	}
	if (!tokenValue) {
		tokenValue = ZEPHIR_GLOBAL(global_null);
	}
	if (!destroyIfValid_param) {
		destroyIfValid = 1;
	} else {
		destroyIfValid = zephir_get_boolval(destroyIfValid_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_exception_ce, "A dependency injection container is required to access the 'session' service", "phalcon/security.zep", 371);
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "session", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(session, _1);
	if (!(zephir_is_true(tokenKey))) {
		_3$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_tokenKeySessionID"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&tokenKey, session, "get", NULL, 0, _3$$4);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(tokenKey))) {
		RETURN_MM_BOOL(0);
	}
	if (!(zephir_is_true(tokenValue))) {
		ZEPHIR_INIT_VAR(_4$$6);
		ZVAL_STRING(_4$$6, "request", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&request, dependencyInjector, "getshared", NULL, 0, _4$$6);
		zephir_check_temp_parameter(_4$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&userToken, request, "getpost", NULL, 0, tokenKey);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(userToken, tokenValue);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_tokenValueSessionID"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&knownToken, session, "get", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(equals);
	ZEPHIR_INIT_NVAR(equals);
	ZVAL_BOOL(equals, zephir_hash_equals(knownToken, userToken));
	_5 = zephir_is_true(equals);
	if (_5) {
		_5 = destroyIfValid;
	}
	if (_5) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "destroytoken", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(equals);

}

/**
 * Returns the value of the CSRF token in session
 */
PHP_METHOD(Phalcon_Security, getSessionToken) {

	zval *dependencyInjector = NULL, *session = NULL, *_0, *_1 = NULL, *_2;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_exception_ce, "A dependency injection container is required to access the 'session' service", "phalcon/security.zep", 424);
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "session", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(session, _1);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_tokenValueSessionID"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(session, "get", NULL, 0, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Removes the value of the CSRF token and key from session
 */
PHP_METHOD(Phalcon_Security, destroyToken) {

	zval *dependencyInjector = NULL, *session = NULL, *_0, *_1 = NULL, *_2, *_3;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_exception_ce, "A dependency injection container is required to access the 'session' service", "phalcon/security.zep", 442);
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "session", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(session, _1);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_tokenKeySessionID"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, session, "remove", NULL, 0, _0);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_tokenValueSessionID"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, session, "remove", NULL, 0, _3);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_token"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_tokenKey"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Computes a HMAC
 */
PHP_METHOD(Phalcon_Security, computeHmac) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool raw;
	zval *data_param = NULL, *key_param = NULL, *algo_param = NULL, *raw_param = NULL, *hmac = NULL, _0, *_1$$3;
	zval *data = NULL, *key = NULL, *algo = NULL, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &data_param, &key_param, &algo_param, &raw_param);

	zephir_get_strval(data, data_param);
	zephir_get_strval(key, key_param);
	zephir_get_strval(algo, algo_param);
	if (!raw_param) {
		raw = 0;
	} else {
		raw = zephir_get_boolval(raw_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_BOOL(&_0, (raw ? 1 : 0));
	ZEPHIR_CALL_FUNCTION(&hmac, "hash_hmac", NULL, 436, algo, data, key, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(hmac))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, phalcon_security_exception_ce);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SV(_2$$3, "Unknown hashing algorithm: %s", algo);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 9, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalcon/security.zep", 465 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(hmac);

}

/**
 * Sets the default hash
 */
PHP_METHOD(Phalcon_Security, setDefaultHash) {

	zval *defaultHash_param = NULL, *_0;
	zend_long defaultHash;

	zephir_fetch_params(0, 1, 0, &defaultHash_param);

	defaultHash = zephir_get_intval(defaultHash_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, defaultHash);
	zephir_update_property_this(getThis(), SL("_defaultHash"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the default hash
 */
PHP_METHOD(Phalcon_Security, getDefaultHash) {

	

	RETURN_MEMBER(getThis(), "_defaultHash");

}

/**
 * Testing for LibreSSL
 */
PHP_METHOD(Phalcon_Security, hasLibreSsl) {

	zval _0 = zval_used_for_init, *_1 = NULL, *_2, *_3;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "OPENSSL_VERSION_TEXT", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "defined", NULL, 249, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_GET_CONSTANT(_2, "OPENSSL_VERSION_TEXT");
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "LibreSSL", 0);
	ZEPHIR_INIT_VAR(_3);
	zephir_fast_strpos(_3, _2, &_0, 0 );
	RETURN_MM_BOOL(ZEPHIR_IS_LONG_IDENTICAL(_3, 0));

}

/**
 * Getting OpenSSL or LibreSSL version
 *
 * Parse OPENSSL_VERSION_TEXT because OPENSSL_VERSION_NUMBER is no use for LibreSSL.
 * @link https://bugs.php.net/bug.php?id=71143
 *
 * <code>
 * if ($security->getSslVersionNumber() >= 20105) {
 *     // ...
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Security, getSslVersionNumber) {

	zval *matches = NULL, *_0, *_1, _2, *patch = NULL, *_4, *_5, *_3$$4;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_GET_CONSTANT(_1, "OPENSSL_VERSION_TEXT");
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "#^(?:Libre|Open)SSL ([\\d]+)\\.([\\d]+)(\\.([\\d]+))?$#", 0);
	zephir_preg_match(_0, &_2, _1, matches, 0, 0 , 0  TSRMLS_CC);
	if (!(zephir_array_isset_long(matches, 2))) {
		RETURN_MM_LONG(0);
	}
	ZEPHIR_INIT_VAR(patch);
	ZVAL_LONG(patch, 0);
	if (zephir_array_isset_long(matches, 3)) {
		zephir_array_fetch_long(&_3$$4, matches, 3, PH_NOISY | PH_READONLY, "phalcon/security.zep", 525 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(patch);
		ZVAL_LONG(patch, zephir_get_intval(_3$$4));
	}
	zephir_array_fetch_long(&_4, matches, 2, PH_NOISY | PH_READONLY, "phalcon/security.zep", 528 TSRMLS_CC);
	zephir_array_fetch_long(&_5, matches, 2, PH_NOISY | PH_READONLY, "phalcon/security.zep", 528 TSRMLS_CC);
	RETURN_MM_LONG(((((10000 * zephir_get_intval(_4))) + ((100 * zephir_get_intval(_5)))) + zephir_get_numberval(patch)));

}

