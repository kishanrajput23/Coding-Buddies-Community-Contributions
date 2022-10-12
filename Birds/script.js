fetch("https://some-random-api.ml/animal/bird")
.then(data=> data.json())
.then(birdData=>
     {
        console.log(birdData['image']);
        const birdImages=birdData['image'];
        const birdElement=document.getElementById('birdElement');
        birdElement.src=birdImages;
     })