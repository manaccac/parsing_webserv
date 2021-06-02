#include "conf.hpp"

conf::conf()
{
    std::cout << "CONSTRUCTOR CALL\n";
    _GET = false;
    _HEAD = false;
    _POST = false;
    _PUT = false;
    _DELETE = false;
    _CONNECT = false;
    _OPTIONS = false;
    _TRACE = false;
}

conf::conf(conf const & s_conf)
{
    std::cout << "COPY CALL\n";
    _GET = s_conf._GET;
    _HEAD = s_conf._HEAD;
    _POST = s_conf._POST;
    _PUT = s_conf._PUT;
    _DELETE = s_conf._DELETE;
    _CONNECT = s_conf._CONNECT;
    _OPTIONS = s_conf._OPTIONS;
    _TRACE = s_conf._TRACE;
}

conf    &conf::operator=(conf const & s_conf)
{
    std::cout << "CONSTRUCTOR CALL\n";
    _GET = s_conf._GET;
    _HEAD = s_conf._HEAD;
    _POST = s_conf._POST;
    _PUT = s_conf._PUT;
    _DELETE = s_conf._DELETE;
    _CONNECT = s_conf._CONNECT;
    _OPTIONS = s_conf._OPTIONS;
    _TRACE = s_conf._TRACE;
    return (*this);
}

conf::~conf()
{
    std::cout << "DESTRUCTOR CALL\n";
}

//set
void conf::set_GET(std::string s_get)
{
    if (s_get.find(" GET ") != ULONG_MAX || s_get.find(" GET;") != ULONG_MAX)
        _GET = true;
    else
		std::cout << "ERREUR GET\n";
}

void conf::set_HEAD(std::string s_head)
{
    if (s_head.find(" HEAD ") != ULONG_MAX || s_head.find(" HEAD;") != ULONG_MAX)
        _HEAD = true;
    else
		std::cout << "ERREUR HEAD\n";
}

void conf::set_POST(std::string s_set)
{
    if (s_set.find(" POST ") != ULONG_MAX || s_set.find(" POST;") != ULONG_MAX)
        _POST = true;
    else
		std::cout << "ERREUR POST\n";
}

void conf::set_PUT(std::string s_set)
{
    if (s_set.find(" PUT ") != ULONG_MAX || s_set.find(" PUT;") != ULONG_MAX)
        _PUT = true;
    else
		std::cout << "ERREUR PUT\n";
}

void conf::set_DELETE(std::string s_set)
{
    if (s_set.find(" DELETE ") != ULONG_MAX || s_set.find(" DELETE;") != ULONG_MAX)
        _DELETE = true;
    else
		std::cout << "ERREUR DELETE\n";
}

void conf::set_CONNECT(std::string s_set)
{
    if (s_set.find(" CONNECT ") != ULONG_MAX || s_set.find(" CONNECT;") != ULONG_MAX)
        _CONNECT = true;
    else
		std::cout << "ERREUR CONNECT\n";
}
void conf::set_OPTIONS(std::string s_set)
{
    if (s_set.find(" OPTIONS ") != ULONG_MAX || s_set.find(" OPTIONS;") != ULONG_MAX)
        _OPTIONS = true;
    else
		std::cout << "ERREUR OPTIONS\n";
}
void conf::set_TRACE(std::string s_set)
{
    if (s_set.find(" TRACE ") != ULONG_MAX || s_set.find(" TRACE;") != ULONG_MAX)
        _TRACE = true;
    else
		std::cout << "ERREUR TRACE\n";
}