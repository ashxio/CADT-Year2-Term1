const track = document.querySelector('.slide-track');
const slides = document.querySelectorAll('.slide-track img');
let index = 0;

function showNextSlide() {
    const slideWidth = slides[0].clientWidth;
    index++;
    if (index >= slides.length) index = 0;
    track.style.transform = `translateX(-${index * slideWidth}px)`;
}

// Slide every 2000ms
let interval = setInterval(showNextSlide, 2000);

    // Data
    const derlgData = [
        {title: "MiMtes", image: "img/yourName.jpeg", description: "Mi mtes hel hel nham pel ngai pleang bussin 10/10. price range is 2.5$ up. open time is 6-7pm, close time midnight "},
        {title: "Kaixin", image: "img/5cmPerSecond.jpeg", description: "Hotpot zin, must try. open time 11am, close time unknown."},
        {title: "Mi Teanh", image: "img/EndGame.jpeg", description: "A chinese place selling noodle with vegetable broth and meat. get a big protion for the price. "},
        {title: "Little ceaser", image: "img/FarFromHome.jpeg", description: "fast food pizza."},
        {title: "Saj ko ang", image: "img/HomeComing.jpeg", description: "comfort food, who even say no to this."}
    ];

    const derlglist = document.getElementById("derlgList");

    derlgData.forEach(data => {
        // Create card container
        const card = document.createElement('div');
        card.className = "derlgCard";

        card.innerHTML = `
            <img src = "${data.image}" alt = "${data.title}" class = "image">
            <div class = "info">
                <h3>${data.title}</h3>
                <p>${data.description}</p>
            </div>
        `; 

        derlglist.appendChild(card);
    });
