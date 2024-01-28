struct Node
{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    Node* get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(Node* node,char ch)
    {
        links[ch - 'a'] = node;
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};


class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i = 0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(new Node(),word[i]);
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool helper(Node* root,string word,int idx)
    {
        if(idx == word.size() && root->isEnd() == false)
        {
            return false;
        }

        if(idx == word.size() && root->isEnd() == true)
        {
            return true;
        }

        if(word[idx] == '.')
        {
            for(int i = 0;i<26;i++)
            {
                bool a;

                if(root->links[i] != NULL)
                {
                    a = helper(root->links[i],word,idx+1);
                }
                if(a == true)
                {
                    return true;               
                }
            }
            return false;
        }
        else
        {
            if(root->links[word[idx] - 'a'] == NULL)
            {
                return false;
            }
            return helper(root->links[word[idx]-'a'],word,idx+1);
        }
    }


    
    bool search(string word) {
        Node* node = root;
        return helper(node,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */