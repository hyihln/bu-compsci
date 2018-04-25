package lab08;

import java.util.ArrayList;

public class ComposedHand {
	private ComputationMethod method;
	ArrayList<Card> cards = new ArrayList<Card>();
	
	public ComposedHand(ComputationMethod method) {
		super();
		this.method = method;
	}
	
	public void addCard(Card c){
		cards.add(c);
	}
	public void clear(){
		cards.clear();
	}
	public String toString(){
		return cards.toString();
	}
	public int value(){
		return method.compute(cards);
	}
}
