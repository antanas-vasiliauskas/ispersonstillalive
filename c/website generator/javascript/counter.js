// Set the date we're counting down to
var countDown = [
(repeat) 0
new Date("|").getTime(),
(endrep)
];

// Update the count down every 1 second
var x = setInterval(function() {

  // Get today's date and time
  var now = new Date().getTime();

  // Find the distance between now and the count down date
  distance = []
  for(var i = 0; i < countDown.length; i++){
    distance.push(now - countDown[i]);
  }

  var days = [];
  var hours = [];
  var minutes = [];
  var seconds = [];
  for(var i = 0; i < countDown.length; i++){
    days.push(Math.floor(distance[i] / (1000 * 60 * 60 * 24)));
    hours.push(Math.floor((distance[i] % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60)));
    minutes.push(Math.floor((distance[i] % (1000 * 60 * 60)) / (1000 * 60)));
    seconds.push(Math.floor((distance[i] % (1000 * 60)) / 1000));
  }

  for (var i = 0; i < countDown.length; i++) {
    document.getElementById("element_" + i).innerHTML = days[i] + " days " + hours[i] + " hours "
  + minutes[i] + " minutes " + seconds[i] + " seconds ";
  }
}, 1000);