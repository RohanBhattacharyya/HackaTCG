cardData = {};

function getBackgroundColor(artNumber) {
    switch (artNumber) {
        case (0):
            return "green"
        case (1):
            return "red"
        case (2):
            return "purple"
        case (3):
            return "blue"
    }
}

function visualizeCards() {
    html = "";
    cardData.forEach(card => {
        html += `
        <div class="card ${card.attrib == 1 ? 'shiny' : ''} ${card.attrib == 2 ? 'plated' : ''} ${getBackgroundColor(card.art)}">
            <span>
                <h2>${card.name}</h2>
                <h3>100/100</h3>
            </span>
            <img src="images/artwork/${card.art}.png">
            <p>Ratticus is the op. He will take your rent, whether your want or not.</p>
        </div>
        `;
    });
    document.querySelector(".pack").innerHTML = html;
}

function fetchCards() {
    fetch('http://localhost:8080/openPack').then(response =>response.json())
    .then(data => {
        console.log(data)
        cardData = data;
        visualizeCards();
    });
}