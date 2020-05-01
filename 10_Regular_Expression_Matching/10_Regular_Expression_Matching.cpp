class Solution {
	public:
		bool isMatch(string s, string p) {
			return isMatch(s.c_str(), p.c_str());
		}
	private:
		bool isMatch(const char* s, const char* p)
		{
			//一起到尾巴
			if(*p == '\0') return *s == '\0';

			//normal case like : p = 'a.' 'aa' 'abc'
			if(p[1] != '*' || p[1] == '\0')
			{
				if(*s == '\0') return false;
				if(*p == '.' || *s == *p)
					return isMatch(s + 1, p + 1);
				else return false;
			}
			else
			{
				int i = -1;
				// "s[i] == *p " 比對前面要一樣
				while(i == -1 || s[i] == *p || *p == '.')
				{
					//比對後面
					if(isMatch(s + i + 1, p + 2)) return true;
                    //p還沒比對完s就沒了
					if(s[++i] == '\0') break;                
				}
				return false;
			}
			return false;
		}
};


