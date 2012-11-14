package  {
	import flash.globalization.StringTools;

	public class equation {
		// data types
		private static const VALUE=0;
		private static const PLUS=1;
		private static const MINUS=2;
		private static const MULTI=3;
		private static const DIV=4;
		// end of data types
		
		private var string:String;
		private var elements = new Array();
		
		public function equation(data) {
			string=data;
			read();
			solve();
		}
		
		public function getString() { return string };
		
		public function read() {
			var buffer:String = new String();
			for(var i=0; i<string.length;i++) {
				if(string.charAt(i)=="." || (string.charAt(i)>="0" && string.charAt(i)<="9")) {
					buffer+=string.charAt(i);
				} else if(string.charAt(i)=="+") {
					elements.push(new element(VALUE, Number(buffer)));
					buffer = new String();
					elements.push(new element(PLUS));
				} else if(string.charAt(i)=="-") {
					elements.push(new element(VALUE, Number(buffer)));
					buffer = new String();
					elements.push(new element(MINUS));
				} else if(string.charAt(i)=="*") {
					elements.push(new element(VALUE, Number(buffer)));
					buffer = new String();
					elements.push(new element(MULTI));
				} else if(string.charAt(i)=="/") {
					elements.push(new element(VALUE, Number(buffer)));
					buffer = new String();
					elements.push(new element(DIV));
				}
			}
			elements.push(new element(VALUE, Number(buffer)));
			buffer = new String();
		}
		
		public function solve() {
			for(var i=1; i<elements.length; i+=2) {
				if(elements[i].getType() == MULTI) {
					elements[i-1].setValue(elements[i-1].getValue()*elements[i+1].getValue());
					elements.splice(i,2);
					i-=2;
				} else if(elements[i].getType() == DIV) {
					elements[i-1].setValue(elements[i-1].getValue()/elements[i+1].getValue());
					elements.splice(i,2);
					i-=2;
				}
			}
			for(i=1; i<elements.length; i+=2) {
				if(elements[i].getType() == MINUS) {
					elements[i-1].setValue(elements[i-1].getValue()-elements[i+1].getValue());
					elements.splice(i,2);
					i-=2;
				} else if(elements[i].getType() == PLUS) {
					elements[i-1].setValue(elements[i-1].getValue()+elements[i+1].getValue());
					elements.splice(i,2);
					i-=2;
				}
			}
			string=elements[0].getValue();
		}
		
	}
	
}
