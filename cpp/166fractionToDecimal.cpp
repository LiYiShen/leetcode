class Solution {
public:
    //С��������������������ξͱ�ʾ��С����ѭ��С����
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) return "";  // �߽���������ĸΪ0
        if (numerator == 0) return "0";  // �߽�����������Ϊ0
        string result;

        // ת��Ϊlonglong��ֹ���
        long long num = static_cast<long long>(numerator);
        long long denom = static_cast<long long>(denominator);

        if ((num > 0)^(denom > 0)) result.push_back('-');  // ���������ţ�һ��һ��ȡ����
        num = llabs(num); denom = llabs(denom);  // ���ӷ�ĸȫ��ת��Ϊ����
        result.append(to_string(num / denom));  // ������������

        // ����С������
        num %= denom;                         // �������
        if (num == 0)return result;             // ����Ϊ0����ʾ�����ˣ�ֱ�ӷ��ؽ��
        result.push_back('.');              // ������Ϊ0�����С����
        int index = result.size() - 1;          // ���С������±�
        unordered_map<int,int> record;      // map������¼�����ظ������±꣬Ȼ��'('���뵽�ظ���ǰ��ͺ���
        while (num && record.count(num) == 0) {   // С�����֣�������Ϊ0��������û�г����ظ�����
            record[num] = ++index;
            num *= 10;                        // ��������10����Ȼ�����̣��Ͳݸ屾�����㷽����һ����
            result += to_string(num / denom);
            num %= denom;
        }
        if (record.count(num) == 1) {           // ����ѭ������������ֱ�����ظ�����ǰ�����'(',�ַ���ĩβ���')'
            result.insert(record[num], "(");
            result.push_back(')');
        }
        return result;
    }
};
