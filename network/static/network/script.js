document.querySelector('#createButton').addEventListener('click', function(){
    createPosts();
})

function createPosts() {

    var createPost = document.getElementById('createPost');
    var createButton = document.getElementById('createButton')

    if (createPost.style.display === "none") {
        createPost.style.display = "block";
        createButton.style.display = "none";
    } else {
        createPost.style.display = "none";
        createButton.style.display = "block";
    }
}

function like(id) {

    fetch(`like/${id}`)
    .then(response => response.json())
    .then(result => {
        console.log(result.result.html);
        document.getElementById(`heart-${id}`).innerHTML = result.result.html
        document.getElementById(`likes-${id}`).innerHTML = result.result.likes
    });
}

function follow(id) {

    fetch(`follow/${id}`)
    .then(response => response.json())
    .then(result => {
        document.getElementById('follow_button').innerHTML = result.result.button;
        document.getElementById('following').innerHTML = `Following: &nbsp&nbsp ${result.result.following}`;
        document.getElementById('followers').innerHTML = `Followers: &nbsp&nbsp ${result.result.followers}`;
    });

}
