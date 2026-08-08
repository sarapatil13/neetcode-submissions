class Codec {
public:

    void serializehelper(TreeNode* root, string& s) {

        if(root == NULL) {
            s += "N,";
            return;
        }

        s += to_string(root->val) + ",";

        serializehelper(root->left, s);
        serializehelper(root->right, s);
    }


    string serialize(TreeNode* root) {

        string s;

        serializehelper(root, s);

        return s;
    }


    TreeNode* deserializehelper(vector<string>& nodes, int& index) {

        if(nodes[index] == "N") {
            index++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(nodes[index]));

        index++;

        root->left = deserializehelper(nodes, index);

        root->right = deserializehelper(nodes, index);

        return root;
    }


    TreeNode* deserialize(string data) {

        vector<string> nodes;

        string temp;

        for(char c : data) {

            if(c == ',') {
                nodes.push_back(temp);
                temp = "";
            }
            else {
                temp += c;
            }
        }

        int index = 0;

        return deserializehelper(nodes, index);
    }
};