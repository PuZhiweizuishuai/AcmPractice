import java.util.*;
/**
 * 2000年1月1日加 n 天后的日期
 * 以 MM-DD-YYYY:DayOfWeek 格式输出
 */
public class CalculateDate2000 {

	public static void main(String[] args) {
		String[] week = new String[]{
                " ",
				"Sunday",
				"Monday", 
				"Tuesday", 
				"Wednesday", 
				"Thursday", 
				"Friday" ,
				"Saturday"
		};
		Scanner sc = new Scanner(System.in);
		Calendar calendar = Calendar.getInstance();
		int day;
		while((day = sc.nextInt()) != -1) {
            calendar.set(2000, 0,1);
			calendar.add(Calendar.DAY_OF_MONTH, day);
			System.out.printf("%02d-%02d-%d:%s\n",(calendar.get(Calendar.MONTH)+1),
					(calendar.get(Calendar.DAY_OF_MONTH)),
					calendar.get(Calendar.YEAR),
                    week[calendar.get(Calendar.DAY_OF_WEEK)]);
		}	
	}
}
