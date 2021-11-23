const Music = require('../models/music')

let getSongs = async (req, res, next) => {
    let songs = []
    try {
        songs = await Music.find({})
    } catch(err) {
        console.log(err)
        return res.send(err)
    }
    res.send({ songs })
}

let addSong = async (req, res, next) => {

    const body = req.body
    let newSong = new Music({
        name: body.name,
        song: body.song,
        date: body.date,
        album: body.album,
        singers: body.singers
    })

    try {
        await newSong.save()
    } catch(err) {
        console.log(err)
        return res.send(err)
    }

    res.send({ song: newSong })
}

let getSongById = async (req, res, next) => {
    let { id } = req.params
    if (!id) return res.send("Enter a valid id")

    let song
    try {
        song = await Music.findById(id)
    } catch(err) {
        console.log(err)
        return res.send(err)
    }
    res.send({ song })
}

let uploadSong = (req, res, next) => {
    const filePath = req.file.path.replace(/\\/g, '/')
    res.send({
        path: filePath
    })
}

let updateSong = async (req, res, next) => {
    let { id } = req.params
    if (!id) return res.send("Enter a valid id")

    let body = req.body
    const updatedSong = {
        name: body.name,
        song: body.song,
        date: body.date,
        album: body.album,
        singers: body.singers
    }

    let newSong
    try {
        newSong = await Music.findByIdAndUpdate(id, updatedSong, {new: true})
    } catch(err) {
        console.log(err)
        return res.send(err)
    }
    res.send({ song: newSong })
}

let deleteSong = async (req, res, next) => {
    let { id } = req.params
    if (!id) return res.send("Enter a valid id")

    let song
    try {
        song = await Music.findById(id)
    } catch(err) {
        console.log(err)
        return res.send(err)
    }

    if (!song) {
        return res.send('No such song present in database')
    }

    try {
        await Music.findByIdAndDelete(id)
    } catch(err) {
        console.log(err)
        return res.send(err)
    }

    return res.send('song deleted')
}

module.exports = { getSongs, addSong, getSongById, uploadSong, updateSong, deleteSong }