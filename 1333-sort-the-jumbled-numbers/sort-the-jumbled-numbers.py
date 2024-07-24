class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        def jumpled_num(num):
            temp_num = num
            pow10 = 1
            mapping_num = 0
            while True:
                digit = temp_num % 10
                mapping_num += mapping[digit] * pow10
                pow10 *= 10
                temp_num //= 10
                if (temp_num == 0):
                    break
            return mapping_num
    
        nums.sort(key=jumpled_num)
        return nums