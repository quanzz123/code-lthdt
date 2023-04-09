$(document).ready(function() {
	var nameList = [];
	var result = $('#result');
	var spinning = false;

	$('#nameList p').each(function() {
		var name = $(this).text().trim();
		var deleteButton = $('<button class="deleteButton">Delete</button>');
		deleteButton.click(function() {
			var index = nameList.indexOf(name);
			if (index > -1) {
				nameList.splice(index, 1);
				$(this).parent().remove();
			}
		});
		$(this).append(deleteButton);
		nameList.push(name);
	});

	$('#addButton').click(function() {
		var newName = $('#nameInput').val().trim();
		if (newName !== '') {
			nameList.push(newName);
			$('#nameList').append('<p>' + newName + ' <button class="deleteButton">Delete</button></p>');
			$('#nameInput').val('');
			var newDeleteButton = $('#nameList p:last-child .deleteButton');
			newDeleteButton.click(function() {
				var index = nameList.indexOf(newName);
				if (index > -1) {
					nameList.splice(index, 1);
					$(this).parent().remove();
				}
			});
		}
	});

	$('#spinButton').click(function() {
		if (!spinning) {
			var randomIndex = Math.floor(Math.random() * nameList.length);
			var selectedName = nameList[randomIndex];
			result.text('Selected: ' + selectedName);
			spinning = true;
			setTimeout(function() {
				spinning = false;
			}, 5000); // Wait 5 seconds before allowing spin again
		}
	});
});
