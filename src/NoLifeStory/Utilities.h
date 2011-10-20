////////////////////////////////////////////////////
// This file is part of NoLifeStory.              //
// Please see SuperGlobal.h for more information. //
////////////////////////////////////////////////////

#define PI 3.1415926535897932384626433832795
#define degtorad 0.01745329251994329576923690768489
#define radtodeg 57.295779513082320876798154814105

inline sf::String tostring(const double& t) {
	static char str[32];
	sprintf(str, "%f", t);
	return str;
}

inline sf::String tostring(const int& t) {
	static char str[32];
	sprintf(str, "%i", t);
	return str;
}

inline sf::String tostring(const int& t, const int& len) {
	static char str[64];
	int size = min(len, sprintf(str+32, "%i", t));
	str[32+size] = '\0';
	memset(str+size-len, '0', len-size);
	return str+size-len;
}

inline double todouble(const sf::String& t) {
	return atof(t.ToAnsiString().c_str());
}

inline int toint(const sf::String& t) {
	return atoi(t.ToAnsiString().c_str());
}

inline double sqr(const double& x) {
	return x*x;
}

inline double pdis(const double& x1, const double& y1, const double& x2, const double& y2) {
	return sqrt(sqr(x1-x2)+sqr(y1-y2));
}

inline double pdir(const double& x1, const double& y1, const double& x2, const double& y2) {
	return radtodeg*atan2(y2-y1, x2-x1);
}

inline double ldx (const double& len, const double& dir) {
	return cos(dir*degtorad)*len;
}

inline double ldy (const double& len, const double& dir) {
	return sin(dir*degtorad)*len;
}

inline double angdif (const double& angle1, const double& angle2) {
	return fmod(fmod(angle1-angle2, 360)+540, 360)-180;
}

inline double sign (const double& x) {
	return x>0?1:x<0?-1:0;
}

inline ostream& operator<< (ostream& l, sf::String& r) {
	return l << r.ToAnsiString();
}

#ifndef NLS_TR2
class path : public string {
public:
	path() : string() {}
	path(const string& other) : string(other) {}
	path(const char* other) : string(other) {}
	inline path operator/ (path other) {
		path result(*this);
		result /= other;
		return result;
	}
	inline path& operator/= (path other) {
		if (length() > 1 and (at(length()-1) == '/' or at(length()-1) == '\\')) {
			erase(length()-1);
		}
		if (other.length() > 0 and (other.at(0) == '/' or other.at(0) == '\\')) {
			other.erase(0,1);
		}
		*this += '/';
		*this += other;
		return *this;
	}
};
inline bool exists (const path& name) {
	ifstream file(name);
	bool check = file.is_open();
	file.close();
	return check;
}
#endif