class Node{
    public:
    int person, time;
    Node(int p, int t){
        person = p;
        time = t;
    }
};

class TopVotedCandidate {
public:
    vector<Node> votes;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        votes.clear();
        vector<int> hashed(5002,0);
        int curr = -1, vote = 0;
        for(int i=0; i<persons.size(); i++){
            int p = persons[i], t = times[i];
            hashed[p]++;
            if(hashed[p]>=vote){
                if(p!=curr){
                    curr = p;
                    votes.push_back(Node(curr,t));
                }
                if(hashed[p]>vote)
                    vote = hashed[p];
            }
        }
    }
    
    int q(int t) {
        int l = 1, h = votes.size();
        while(l<h){
            int mid = l + (h-l)/2;
            if(votes[mid].time <= t)
                l = mid+1;
            else
                h = mid;
        }
        return votes[l-1].person;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */