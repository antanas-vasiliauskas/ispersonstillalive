
// Set the date we're counting down to
var countDownDate = new Date("Sep 8, 2022 17:10:00").getTime();
var countDownDateKennedy = new Date("Nov 22, 1963 20:30:00").getTime();
var countDownDateKobe = new Date("Jan 26, 2020 16:45:00").getTime();

// Update the count down every 1 second
var x = setInterval(function() {

  // Get today's date and time
  var now = new Date().getTime();

  // Find the distance between now and the count down date
  var distance = now - countDownDate;
  var distanceKennedy = now - countDownDateKennedy
  var distanceKobe = now - countDownDateKobe

  // Time calculations for days, hours, minutes and seconds
  var days = Math.floor(distance / (1000 * 60 * 60 * 24));
  var hours = Math.floor((distance % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
  var minutes = Math.floor((distance % (1000 * 60 * 60)) / (1000 * 60));
  var seconds = Math.floor((distance % (1000 * 60)) / 1000);

    // Time calculations for days, hours, minutes and seconds
    var daysKennedy = Math.floor(distanceKennedy / (1000 * 60 * 60 * 24));
    var hoursKennedy = Math.floor((distanceKennedy % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
    var minutesKennedy = Math.floor((distanceKennedy % (1000 * 60 * 60)) / (1000 * 60));
    var secondsKennedy = Math.floor((distanceKennedy % (1000 * 60)) / 1000);

      // Time calculations for days, hours, minutes and seconds
  var daysKobe = Math.floor(distanceKobe / (1000 * 60 * 60 * 24));
  var hoursKobe = Math.floor((distanceKobe % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
  var minutesKobe = Math.floor((distanceKobe % (1000 * 60 * 60)) / (1000 * 60));
  var secondsKobe = Math.floor((distanceKobe % (1000 * 60)) / 1000);

  // Display the result in the element with id="demo"
  document.getElementById("elizabeth-ii-timer").innerHTML = days + " days " + hours + " hours "
  + minutes + " minutes " + seconds + " seconds ";

    // Display the result in the element with id="demo"
    document.getElementById("kennedy-timer").innerHTML = daysKennedy + " days " + hoursKobe + " hours "
    + minutesKobe + " minutes " + secondsKobe + " seconds ";

      // Display the result in the element with id="demo"
  document.getElementById("kobe-timer").innerHTML = daysKobe + " days " + hoursKobe + " hours "
  + minutesKobe + " minutes " + secondsKobe + " seconds ";

  // If the count down is finished, write some text
  if (distance < 0) {
    clearInterval(x);
    document.getElementById("demo").innerHTML = "EXPIRED";
  }
}, 1000);
