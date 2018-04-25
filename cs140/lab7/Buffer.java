package lab07;

import java.util.List;

public class Buffer {
	protected List<String> lines;
	public int getNumlines(){
		return lines.size();
	}
	public String getText(){
		return String.join("\n", this.lines);
	}
	public void draw(){
		System.out.println(this.getText());
	}
	public void save() throws Exception{
		throw new UnsupportedOperationException();
	}
	public void type(String toType){
		if(lines.size()==0){
			lines.add("");
		}
		char[] chars = toType.toCharArray();
		for(int i=0; i<toType.length();i++){
			if(chars[i]=='\n'){
				lines.add("");
			}
			else{
				lines.add(Character.toString(chars[i]));
			}
		}
	}
}
