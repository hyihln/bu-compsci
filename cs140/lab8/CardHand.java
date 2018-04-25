package lab08;

import java.util.ArrayList;

public abstract class CardHand {
	ArrayList<Card> cards = new ArrayList<Card>();
	
	public void addCard(Card c){
		cards.add(c);
	}
	public void clear(){
		cards.clear();
	}
	public String toString(){
		return cards.toString();
	}
	public abstract int value();
}
