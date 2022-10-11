window.addEventListener("load", () => {
  const sounds = document.querySelectorAll(".sound");
  const pads = document.querySelectorAll(".pads div");
  const visual = document.querySelector(".visual");
  const colors = [
    "#b23bd6",
    "#6068d3",
    "#d39460",
    "#60d379",
    "#c2d360",
    "#d3a560",
    "#8b1c25"
  ];

  document.addEventListener("keydown", function (event) {
    const getKey = event.which;
    const createKeys = [68, 70, 71, 72, 74, 75, 76];
    const getKeyIndex = createKeys.indexOf(getKey);
    if (createKeys.includes(getKey)) {
      sounds[getKeyIndex].currentTime = 0;
      sounds[getKeyIndex].play();
      createBubble(getKeyIndex);
    }
  });

  pads.forEach((pad, index) => {
    pad.addEventListener("click", function() {
      sounds[index].currentTime = 0;
      sounds[index].play();
      createBubble(index);
    });
  });

  const createBubble = index => {
    //Create bubbles
    const bubble = document.createElement("div");
    visual.appendChild(bubble);
    bubble.style.backgroundColor = colors[index];
    bubble.style.animation = `jump 1s ease`;
    bubble.addEventListener("animationend", function() {
      visual.removeChild(this);
    });
  };
});
