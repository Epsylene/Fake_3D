class pSObject {
    constructor(x, y, z, l) {
        this.pos = new Vector(x, y, z);
        this.l = l;
    }

    update(dt, everyObjects) { }

    draw(drawer)
    {
        drawer.noStroke()
              .fill(255, 255, 255)
              .rect(this.pos.x, this.pos.y, this.l, this.l);
    }
}
