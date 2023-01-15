// Set the date we're counting down to
var countDown = [
new Date("2022-9-8 17:10:0").getTime(),
new Date("1952-10-7 9:30:0").getTime(),
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