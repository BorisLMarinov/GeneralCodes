let startedGame = false;

let flyX,
    flyY,
    flyDead,
    flyDY,
    initFlyC,
    flyDelta,
    flyW,
    flyTimer;

// Spawn fly at random position
function spawnFly(x, y) {
    flyX.push(x);
    flyY.push(y);
    flyDead.push(false);
    flyDY.push(-Math.random()*5);
}
function areCirclesColliding(x1,y1,r1,x2,y2,r2){
    return (x1 - x2) * (x1 - x2) + (y1 -y2) * (y1 - y2) <= (r1 - r2) * (r1 - r2);
}

// Spawn fly outside of canvas
function spawnRandomOutside() {
    let x = canvas.width / 2, y = canvas.height / 2;
    while (areColliding(x, y, flyW, flyW, 0, 0, canvas.width, canvas.height)) {
        x = randomInteger(canvas.width + spawnW*2) - spawnW;
        y = randomInteger(canvas.height + spawnW*2) - spawnW;
    }
    spawnFly(x, y);
}

// Execute callback function for each fly
function forEachFly(cb) {
    for(let i = 0; i < flyX.length; i++) {
        cb(i);
    }
}

let explosionTimer,
    explosionW,
    targetX,
    targetY,
    targetW,
    lives,
    spawnW;

let flyImg = tryToLoad("evil_fly_idl", "green");
let flyDeath = tryToLoad("evil_fly_death", "green");
let explosion = tryToLoad("explosion", "green");
let bg_audio =  new Audio('duel_of_the_fates.mp3');

function init() {
    // Preload images
    drawImage(flyImg);
    drawImage(flyDeath);
    drawImage(explosion);

    startedGame = false;
}

// Init function for all variables
// Can be used to restart game
function startGame() {
    startedGame = true;
    flyX = [];
    flyY = [];
    flyDead = [];
    flyDY = [];
    initFlyC = 1000;
    flyDelta = 5;
    flyW = 40;
    flyTimer = 0;
    explosionTimer = 0;
    explosionW = 200;
    targetX = 400;
    targetY = 300;
    targetW = 100,
    lives = 2000;
    spawnW = 300;
    // Spawn initial flies
    while(flyX.length < initFlyC) {
        spawnRandomOutside();
    }
}

// Updates dead fly with index i
function updateDeadFly(i) {
    // If fly is dead - it falls down
    flyDY[i] += 0.1;
    flyY[i] += flyDY[i];
}
// Update not dead fly with index i
function updateAliveFly(i) {
    // Move randomly
    flyX[i] += Math.random() * flyDelta - flyDelta / 2;
    flyY[i] += Math.random() * flyDelta - flyDelta / 2;

    // Move towards target 
    flyX[i] += (targetX - flyX[i]) / 500;
    flyY[i] += (targetY - flyY[i]) / 500;

    // If fly collied with target
    let w = targetW;
    if (areCirclesColliding(targetX , targetY , targetW, flyX[i] + flyW/2, flyY[i] + flyW/2, flyW)) {
        // Spawn new fly in its place
        flyDead[i] = true;
        spawnRandomOutside();
        lives--;

        if (lives < 0) {
            // Stop game
            startedGame = false;
        }
    }
}
function update() {
    if (startedGame) {
        flyTimer++;
        // Update flies
        forEachFly(function(i) {
            // If fly is dead 
            if (flyDead[i]) {
                updateDeadFly(i)
            } else {
                // If fly is alive
                updateAliveFly(i);
            }
        });
        

        if (explosionTimer > 0) {
            explosionTimer--;
        }
    }
}
function drawMain() {
    // Draw flies
    forEachFly(function(i) {
        let fly_n = Math.floor(flyDead[i] ? (6) : (flyTimer / 3)) % 10;
        let img = flyDead[i] ? flyDeath : flyImg;
        context.drawImage(img.img, 300 * fly_n, 0, 300, 219, flyX[i], flyY[i], flyW, flyW);
    });
    // Draw target
    let w = targetW;
    drawImage(cherry, targetX - w / 2, targetY - w / 2, w, w);

    // Draw lives
    for (let i = 0; i < lives; i++) {
        drawImage(heart, 0, i * 30, 30, 30);
    }
    // Draw spank animation
    if (explosionTimer > 0) {
        let spank_n = Math.floor(explosionTimer / 4) % 12;
        context.drawImage(explosion.img, 12 * 96 - 96 * spank_n, 0, 96, 96,
            mouseX - explosionW / 2, mouseY - explosionW / 2, explosionW, explosionW);
    }
}
function draw() {
    drawImage(backClouds, 0, 0, canvas.width, canvas.height);

    if (startedGame) {
        drawMain();
    } else {
        context.fillStyle = "gray"
        context.fillRect(150, 272, 500, 100)
        context.font = "50px Courier New";
        context.fillStyle = "black"
        context.fillText("Click To Start!", 200, 300);
    }
}
function mouseup() {
    // If game is not started - start it on click
    if (!startedGame) {
        startGame();
        bg_audio.play();
        return;
    }

    // Start explosion animation
    explosionTimer = 48;

    // Kill flies around mouse
    forEachFly(function (i) {
        if(areCirclesColliding(mouseX, mouseY, explosionW,
                        flyX[i]+ flyW/2, flyY[i]+flyW/2, flyW) &&
            !flyDead[i]) {
            flyDead[i] = true;
            spawnRandomOutside();
        }
    })
}