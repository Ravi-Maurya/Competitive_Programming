class Solution {
public:
    string validIPAddress(string IP) {
        string status = "Neither";
        
        auto nums = tokenizeString(IP, '.');
        if (size(nums) > 1) {
            if (!isdigit(IP.front()) || !isdigit(IP.back())) {
                return status;
            }
            if (size(nums) != 4) return status;
            status = validateIPv4(nums) ? "IPv4" : status;
        }
        
        
        if (size(nums) == 1) {
            nums = tokenizeString(IP, ':');
            if (size(nums) > 1) {
                if (!isalnum(IP.front()) || !isalnum(IP.back())) {
                    return status;
                }
                if (nums.size() != 8) return status;
                status = validateIPv6(nums) ? "IPv6" : status;
            }
        }
        
        return status;
    }

private:
    bool validateIPv4(const vector<string>& nums) {
        for (const auto& num : nums) {
            if (num.empty() || num.size() > 3) return false;
            
            if (num.size() > 1 && num[0] == '0') {
                return false;
            }
                
            for (auto c : num) if (!isdigit(c)) return false;
                
            auto digits = stoi(num);
            if (digits < 0 || digits > 255) {
                return false;
            }
        }
        return true;
    }
    
    bool validateIPv6(const vector<string>& nums) {
        for (const auto& num : nums) {
            if (num.empty()) return false;
            
            if (num.size() > 4) return false;
            
            for (auto c : num) {
                if (!isalnum(c)) return false;
                
                if (isalpha(c) && tolower(c) > 'f') {
                    return false;   
                }
            }
        }
        
        return true;
    }
    
    vector<string> tokenizeString(const string& str, char delimiter) {
        stringstream ss(str);
        string buffer;
        
        vector<string> res;
        while (getline(ss, buffer, delimiter)) {
            res.emplace_back(buffer);
        }
        
        return res;
    }
};