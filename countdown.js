(function ($) {
  var currentdate = new Date();
  var now = Math.round(new Date().getTime()/1000.0);
  var beer_o_clock = Drupal.settings.beer_o_clock.boc_timer;
  var diff = beer_o_clock - now;
  var seconds_min = Math.floor(diff / 60);
  var minutes = seconds_min % 60;
  var hour_min = Math.floor(seconds_min / 60);
  var hours = hour_min % 24;
  var hour_day = Math.floor(hour_min / 24);
  var days = hour_day % 365;
	
	//http://stackoverflow.com/questions/1267283/how-can-i-create-a-zerofilled-value-using-javascript
	function zeroFill( number, width )
	{
  width -= number.toString().length;
  if ( width > 0 )
  {
    return new Array( width + (/\./.test( number ) ? 2 : 1) ).join( '0' ) + number;
  }
  return number + ""; // always return a string
	}
	
	setInterval(function () {
		var seconds = diff % 60;
		$("#boc_timer").text(zeroFill(days, 2)+":"+zeroFill(hours,2)+":"+zeroFill(minutes,2)+":"+zeroFill(seconds,2));	
	console.log(zeroFill(days, 2)+":"+zeroFill(hours,2)+":"+zeroFill(minutes,2)+":"+zeroFill(seconds,2));
		diff--;
	}, 1000);

})(jQuery);


