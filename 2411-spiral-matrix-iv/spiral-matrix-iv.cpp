/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> answer(m, vector<int>(n, -1));
        int row = 0, col = 0, step = 0;
        int x, y;
        while (head){
            answer[row][col] = head->val;
            x = col + dx[step];
            y = row + dy[step];
            if (x < 0 || x >= n || y < 0 || y >= m || answer[y][x] != -1){
                step = (step + 1) % 4;
            }
            row += dy[step];
            col += dx[step];
            head = head->next;
        }
        return answer;
    }
};