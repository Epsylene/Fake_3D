class pSObject {
    constructor() {
        this.portals = [] //Tableau dynamique contenant nos portails
        this.t = 0; //Compteur utilisé dans update() pour éviter
                    // de créer trop de portails d'un coup
        this.fl = 1; //Distance focale
    }

    randomInt(min, max) {
        return Math.round(random(min, max));
    }

    addPortal() {
        let x = this.randomInt(-50, 50);
        let y = this.randomInt(-50, 50);
        let z = 1;
        let v = this.randomInt(1, 5);
        let l = this.randomInt(10, 30);
        let p = 1;

        this.portals.push({x, y, z, v, l, p});
    }

    update(dt, everyObjects) {
        for (var i = 0; i < this.portals.length; i++) {
            this.portals[i].z += this.portals[i].v * dt;
            this.portals[i].p = this.fl / this.portals[i].z;
        }

        if(this.t % 100 == 0) {
            this.addPortal();
        }

        this.t++;
    }

    draw(drawer)
    {
        for (var i = 0; i < this.portals.length; i++) {
            drawer.noStroke()
                  .fill(255, 255, 255)
                  .rect(this.portals[i].x * this.portals[i].p,
                        this.portals[i].y * this.portals[i].p,
                        this.portals[i].l * this.portals[i].p,
                        this.portals[i].l * this.portals[i].p);
        }

    }
}
