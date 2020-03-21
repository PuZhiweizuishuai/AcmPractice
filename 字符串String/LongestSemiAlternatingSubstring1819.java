
/**
 * https://www.lintcode.com/problem/longest-semi-alternating-substring/description
 */
public class LongestSemiAlternatingSubstring1819 {
	public static void main(String[] args) {
		String s = "baaabbabbb";
		System.out.println(Tes(s));
		System.out.println(longestSemiAlternatingSubstring(s));

	}

	public static int Tes(String s) {
		int count = 1, lastSeen = 0, l = 0;
		int res = 0;
		for (int end = 1; end < s.length(); end++) {
			char c = s.charAt(end);
			if (s.charAt(end - 1) == c) {
				count++;
			} else {
				count = 1;
				lastSeen = end;
			}

			if (count > 2 && l < lastSeen) {
				l = lastSeen;
			}

			while (count > 2) {
				count--;
				l++;
			}
			res = Math.max(res, end - l + 1);
		}
		return res;
	}

	public static int longestSemiAlternatingSubstring(String s) {
		if (s == null || s.length() == 0) {
			return 0;
		}
		if (s.length() <= 3) {
			return s.length();
		}

		// cnt 末尾连续字母的
		// 末尾连续字母的开始 l
		int cnt = 1, l = 0, lastSeen = 0;
		int res = 0;
		for (int r = 1; r < s.length(); r++) {
			char c = s.charAt(r);
			if (s.charAt(r - 1) == c) {
				cnt++;
			} else {
				cnt = 1;
				// 记录连续字符的结尾
				lastSeen = r;
			}
			if (cnt > 2 && l < lastSeen) {
				l = lastSeen;
			}

			while (cnt > 2) {
				l++;
				cnt--;
			}
			// 结束位置加开始位置
			res = Math.max(res, r - l + 1);
		}
		return res;
	}
}