#ifndef __KEYCODE_H__
#define __KEYCODE_H__

#ifdef  __APPLE__
#   define _APPL
#   include <ApplicationServices/ApplicationServices.h>
#elif _WIN32
#   define _WIN
#   define NOMINMAX
#   include <windows.h>
#endif


#ifdef _APPL
namespace __darwin_ {
namespace __action_ {
enum __code_ {
    key_down        = kCGEventKeyDown,
    key_up          = kCGEventKeyUp
};
}

namespace __key_ {
enum __code_ {
    a               =   0,
    s               =   1,
    d               =   2,
    f               =   3,
    h               =   4,
    g               =   5,
    z               =   6,
    x               =   7,
    c               =   8,
    v               =   9,
    b               =  11,
    q               =  12,
    w               =  13,
    e               =  14,
    r               =  15,
    y               =  16,
    t               =  17,
    _1              =  18,
    _2              =  19,
    _3              =  20,
    _4              =  21,
    _6              =  22,
    _5              =  23,
    equal           =  24,
    _9              =  25,
    _7              =  26,
    minus           =  27,
    _8              =  28,
    _0              =  29,
    rightbracket    =  30,
    o               =  31,
    u               =  32,
    leftbracket     =  33,
    i               =  34,
    p               =  35,
    l               =  37,
    j               =  38,
    k               =  40,
    n               =  45,
    m               =  46,
    ret             =  36,
    quote           =  39,
    semi            =  41,
    slash           =  42,
    comma           =  43,
    dot             =  47,
    tab             =  48,
    space           =  49,
    backspace       =  51,
    enter           =  52,
    escape          =  53,
    clear           =  71,
    f5              =  96,
    f6              =  97,
    f7              =  98,
    f3              =  99,
    f8              = 100,
    f9              = 101,
    f12             = 103,
    f10             = 109,
    insert          = 114,
    home            = 115,
    del             = 117,
    f4              = 118,
    end             = 119,
    f2              = 120,
    f1              = 122,
    left            = 123,
    right           = 124,
    down            = 125,
    up              = 126,
    null            = 128
};}}

#elif defined _WIN
namespace __win32_ {
namespace __action_ {
enum __code_ {
    key_down        = WM_KEYDOWN,
    key_up          = WM_KEYUP
};
}

namespace __key_ {
enum __code_ {
    backspace       =   8,
    tab             =   9,
    enter           =  13,
    shift           =  16,
    ctrl            =  17,
    alt             =  18,
    escape          =  27,
    left            =  37,
    up              =  38,
    right           =  39,
    down            =  40,
    _0              =  48,
    _1              =  49,
    _2              =  50,
    _3              =  51,
    _4              =  52,
    _5              =  53,
    _6              =  54,
    _7              =  55,
    _8              =  56,
    _9              =  57,
    a               =  65,
    b               =  66,
    c               =  67,
    d               =  68,
    e               =  69,
    f               =  70,
    g               =  71,
    h               =  72,
    i               =  73,
    j               =  74,
    k               =  75,
    l               =  76,
    m               =  77,
    n               =  78,
    o               =  79,
    p               =  80,
    q               =  81,
    r               =  82,
    s               =  83,
    t               =  84,
    u               =  85,
    v               =  86,
    w               =  87,
    x               =  88,
    y               =  89,
    z               =  90,
    null            = 128
};}}
#endif


namespace event {
#ifdef _APPL
typedef __darwin_::__key_::__code_      key;
typedef __darwin_::__action_::__code_   action;
#elif defined _WIN
typedef __win32_::__key_::__code_       key;
typedef __win32_::__action_::__code_    action;
#endif

static constexpr const int& code_size = 128;
}


#include <type_traits>
#include <utility>

#define __IS_EVENT_TYPE(x) \
    std::is_same_v<x, event::key> || \
    std::is_same_v<x, event::action>

template <typename _T> struct __is_event_type_pair : std::false_type {};
template <typename _1, typename _2>
    requires __IS_EVENT_TYPE(_1) && __IS_EVENT_TYPE(_2)
struct __is_event_type_pair<std::pair<_1, _2>> : std::true_type {};

typedef std::pair<event::key, event::action> event_pair;

#define __IS_EVENT_TYPE_PAIR(x) __is_event_type_pair<x>::value
#define __IS_EVENT_PAIR(x) std::is_same_v<x, event_pair>

#define _IS_EVENT_TYPE(x) \
    __IS_EVENT_TYPE(x) || \
    __IS_EVENT_TYPE_PAIR(x) || \
    __IS_EVENT_PAIR(x)

#define _IS_EVENT_PAIR(x) \
    __IS_EVENT_PAIR(x)

#define _REQUIRES_EVENT_TYPE(x) requires _IS_EVENT_TYPE(x)

#endif /* __KEYCODE_H__ */