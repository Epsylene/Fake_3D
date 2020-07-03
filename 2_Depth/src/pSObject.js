class pSObject {
    constructor(x, y, z, v, l) {
        this.pos = new Vector(x, y, z);
        this.vel = new Vector(0, 0, v);
        this.l = l;
        this.fl = 1;
        this.p = 1;
    }

    update(dt, everyObjects) {
        this.pos.z += this.vel.z * dt;
        this.p = this.fl / this.pos.z;
    }

    draw(drawer)
    {
        drawer.noStroke()
              .fill(255, 255, 255)
              .rect(this.pos.x * this.p, this.pos.y * this.p, this.l * this.p, this.l * this.p);
    }
}
