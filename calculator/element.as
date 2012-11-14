package  {
	
	public class element {
		private var datatype:int;
		private var evalue:Number;
		public function element(type:int, val:Number=0) {
			datatype=type;
			evalue=val;
		}
		public function getType():int { return datatype; }
		public function getValue():Number { return evalue; }
		public function setValue(val:Number):void { evalue=val }
	}
	
}
