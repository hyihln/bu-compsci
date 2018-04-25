package lab08;

public class BlackjackHand extends CardHand{
	
	public int value(){
		int sum = 0;
		int count = 0;
		for(int i=0;i<cards.size();i++){
			if(cards.get(i).getValue() != 11){
				sum = sum += cards.get(i).getValue();
			}
			else{
				count++;
			}
		}
		for(int i= 0; i<cards.size();i++){
			if(cards.get(i).getValue() == 11){
				if(sum + 11 < 22){
					sum = sum +11;
				}
				else{
					sum = sum +1;
				}
			}
		}
		return sum;
	}
}
